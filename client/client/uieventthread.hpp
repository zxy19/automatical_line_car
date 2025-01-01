#ifndef UIEVENTTHREAD_H
#define UIEVENTTHREAD_H

#include <QWidget>
#include <QThread>
template<typename  T, typename  F>
class UiEventThread : public QThread{

private:
    T *widget;
    F toRunFunction;
public:
    UiEventThread(T *target, F toRunFunction){
        this->toRunFunction = toRunFunction;
        this->widget = target;
    }

protected:
    void run(){
        ((this->widget)->*(this->toRunFunction))();
    }
};

#endif // UIEVENTTHREAD_H
