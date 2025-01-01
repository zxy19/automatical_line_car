#include "formviewer.h"
#include "ui_formviewer.h"
#include <QAxObject>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

FormViewer::FormViewer(QWidget *parent,QByteArray ba) :
    QWidget(parent),
    ui(new Ui::FormViewer),
    model(0,10,this)
{
    ui->setupUi(this);
    QList<QStandardItem*> modelRow;
    modelRow.append(new QStandardItem("灰度1"));
    modelRow.append(new QStandardItem("灰度2"));
    modelRow.append(new QStandardItem("灰度3"));
    modelRow.append(new QStandardItem("灰度4"));
    modelRow.append(new QStandardItem("灰度5"));
    modelRow.append(new QStandardItem("人体1"));
    modelRow.append(new QStandardItem("人体2"));
    modelRow.append(new QStandardItem("人体3"));

    modelRow.append(new QStandardItem("速度左"));
    modelRow.append(new QStandardItem("速度右"));

    this->model.appendRow(modelRow);
    for(int i=0;i+2<ba.length();i+=3){
        uint8_t sensorData= ba.at(i);
        int speedL = ba.at(i+1);
        int speedR = ba.at(i+2);
        QList<QStandardItem*> modelRow;
        for(int j=0;j<8;j++){
            modelRow.append(new QStandardItem(QString::number((sensorData>>j)&0x01)));
        }
        modelRow.append(new QStandardItem(QString::number(speedL)));
        modelRow.append(new QStandardItem(QString::number(speedR)));
        this->model.appendRow(modelRow);
    }
    this->ui->tableView->setModel(&(this->model));
    this->saveCSV = new UiEventThread<FormViewer,void (FormViewer::*)()>(this,&(FormViewer::doSaveCSV));
    this->saveExcel = new UiEventThread<FormViewer,void (FormViewer::*)()>(this,&(FormViewer::doSaveExcel));
    connect(this,SIGNAL(sig_set_finish()),this,SLOT(set_finish()));
    connect(this,SIGNAL(sig_set_progress(int)),this,SLOT(set_progress(int)));
}

FormViewer::~FormViewer()
{
    delete ui;
}
/**
 * 保存excel的相关代码摘自PDF且基本未经过修改
 * @copyright 未经允许；不得传播和出版、培训；中国计量大学－机电工程学院－陈锡爱,程祥辉；xachen@cjlu.edu.cn
 */
void FormViewer::doSaveExcel(){
    QAxObject *excel = new QAxObject("Excel.Application");
    if (excel->isNull())
    {
        if (excel != NULL)//网络中很多使用 excel==NULL 判断，是错误的
        {
            excel->dynamicCall("Quit()");
            delete excel;
        }
        QMessageBox::critical(0, "错误信息", "没有找到 EXCEL 应用程序");
        return;
    }
    QAxObject *workbooks = NULL;
    QAxObject *workbook = NULL;
    QAxObject *worksheets = NULL;
    QAxObject *worksheet = NULL;
    excel->dynamicCall("SetVisible (bool)", false);//不显示窗体
    excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为 true 那么在关闭是会出现类似“文件已修改，是否保存”的提示
    workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
    if (QFile::exists(fileName))
    {
        workbook = workbooks->querySubObject("Open(const QString &)", fileName);
    }
    else
    {
        workbooks->dynamicCall("Add");//新建一个工作簿
        workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
    }
    worksheets = workbook->querySubObject("Sheets");//获取工作表集合
    worksheet = worksheets->querySubObject("Item(int)",1);//获取工作表集合的工作表 1，即sheet1

    QAxObject * usedrange = worksheet->querySubObject("UsedRange");//获取该 sheet 的使用范围对象
    QAxObject * rows = usedrange->querySubObject("Rows");
    QAxObject * columns = usedrange->querySubObject("Columns");
    int intRowStart = usedrange->property("Row").toInt();
    int intColStart = usedrange->property("Column").toInt();
    int intCols = columns->property("Count").toInt();
    int intRows = rows->property("Count").toInt();
    QAxObject *cell = NULL;
    QString str;
    int rowCount = this->model.rowCount();
    int colCount = this->model.columnCount();
    for(int i=intRowStart;i <intRowStart + intRows;i++)
    {
        for(int j=intColStart ;j<intColStart+intCols;j++)
        {
            cell = worksheet->querySubObject("Cells(int,int)", i,j ); //获取单元格
            cell->setProperty("Value", "");
        }

        emit sig_set_progress((int)(30.0 * (i - intRowStart) / intRows));
    }
// 插入数据
    for (int i = intRowStart; i < intRowStart+rowCount; i++)
    {
        for(int j = intColStart; j < intColStart+colCount; j++)
        {
            QModelIndex indextemp = this->model.index(i-intRowStart, j-intColStart);

            QVariant str = this->model.data(indextemp);
            cell = worksheet->querySubObject("Cells(int,int)", i, j);//获取单元格
            cell->setProperty("Value", str);
        }
        emit sig_set_progress(30 + (int)(70.0 * (i - intRowStart) / intRows));
    }
    workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    delete workbook;
    delete workbooks;
    delete excel;
    emit sig_set_finish();
}


/**
 * @copyright 未经允许；不得传播和出版、培训；中国计量大学－机电工程学院－陈锡爱,程祥辉；xachen@cjlu.edu.cn
 */
void FormViewer::doSaveCSV(){
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        emit sig_error_fail_open();
        return;
    }
    QTextStream out(&file);
    QString str;
    //获取表格内容
    int row = this->model.rowCount();
    int col = this->model.columnCount();
    for(int i = 0; i < row; i ++)
    {
        for(int j = 0; j < col; j++)
        {
            if(j != 0)out << str << ",";// 写入文件
            QModelIndex indextemp = this->model.index(i, j);
            str = this->model.data(indextemp).toString();
        }
        emit sig_set_progress((int)(100.0 * i / row));
        out << "\n";
    }
    file.close();
    emit sig_set_finish();
}

void FormViewer::on_pushButton_2_clicked()
{
    fileName = QFileDialog::getSaveFileName(this,"","","Excel文档(*.csv *.txt)");
    this->ui->progressBar->setValue(0);
    this->ui->pushButton->setEnabled(false);
    this->ui->pushButton_2->setEnabled(false);
    this->saveCSV->start();
}

void FormViewer::on_pushButton_clicked()
{
    fileName = QFileDialog::getSaveFileName(this,"","","Excel文档(*.xls *.xlsx)");
    this->ui->progressBar->setValue(0);
    this->ui->pushButton->setEnabled(false);
    this->ui->pushButton_2->setEnabled(false);
    this->saveExcel->start();
}

void FormViewer::set_progress(int p){
    this->ui->progressBar->setValue(p);
}
void FormViewer::set_finish(){
    this->ui->pushButton->setEnabled(true);
    this->ui->pushButton_2->setEnabled(true);
}
void FormViewer::error_fail_open(){
    QMessageBox::critical(this,"文件保存失败","无法打开目标文件",QMessageBox::Ok,QMessageBox::NoButton);
}
