var chart = echarts.init(document.getElementById("chart"));
var chart_sensor = echarts.init(document.getElementById("chart-sensor"));

var dataSensor1 = [];
var dataSensor2 = [];
var dataSensor3 = [];
var dataSensor4 = [];
var dataSensor5 = [];
var dataSensor6 = [];
var dataSensor7 = [];
var dataSensor8 = [];
var dataSpeed1 = [];
var dataSpeed2 = [];
var xSerials = [];
for (var i = 0; i < 100; i++) {
  xSerials.push(i * 0.5);
  dataSensor1.push(0);
  dataSensor2.push(0);
  dataSensor3.push(0);
  dataSensor4.push(0);
  dataSensor5.push(0);
  dataSensor6.push(0);
  dataSensor7.push(0);
  dataSensor8.push(0);
  dataSpeed1.push(0);
  dataSpeed2.push(0);
}
var t = 0;
function addData(dataObj, noUpdate = false) {
  dataSensor1.pop();
  dataSensor2.pop();
  dataSensor3.pop();
  dataSensor4.pop();
  dataSensor5.pop();
  dataSensor6.pop();
  dataSensor7.pop();
  dataSensor8.pop();
  dataSpeed1.pop();
  dataSpeed2.pop();
  dataSensor1.unshift(dataObj.s[0]);
  dataSensor2.unshift(dataObj.s[1]);
  dataSensor3.unshift(dataObj.s[2]);
  dataSensor4.unshift(dataObj.s[3]);
  dataSensor5.unshift(dataObj.s[4]);
  dataSensor6.unshift(dataObj.s[5]);
  dataSensor7.unshift(dataObj.s[6]);
  dataSensor8.unshift(dataObj.s[7]);
  dataSpeed1.unshift(dataObj.l);
  dataSpeed2.unshift(dataObj.r);

  xSerials.pop();
  xSerials.unshift(t.toFixed(1));
  t+=0.5;
  if (noUpdate) return;
  updateChart();
}
function updateChart() {
  chart.setOption({
    animationDuration: 200,
    xAxis: {
      data: xSerials,
    },
    series: [
      {
        name: "速度左",
        type: "line",
        data: dataSpeed1,
      },
      {
        name: "速度右",
        type: "line",
        data: dataSpeed2,
      },
    ],
  });
  chart_sensor.setOption({
    animationDuration: 200,
    xAxis: {
      data: xSerials,
    },
    series: [
      {
        name: "灰度1",
        type: "line",
        data: dataSensor1,
      },
      {
        name: "灰度2",
        type: "line",
        data: dataSensor2,
      },
      {
        name: "灰度3",
        type: "line",
        data: dataSensor3,
      },
      {
        name: "灰度4",
        type: "line",
        data: dataSensor4,
      },
      {
        name: "灰度5",
        type: "line",
        data: dataSensor5,
      },
      {
        name: "人体1",
        type: "line",
        data: dataSensor6,
      },
      {
        name: "人体2",
        type: "line",
        data: dataSensor7,
      },
      {
        name: "人体3",
        type: "line",
        data: dataSensor8,
      }
    ],
  });
}
chart_sensor.setOption({
  animationDuration: 100,
  title: {
    text: "传感器",
  },
  toolbox: {
    feature: {
      dataZoom: {
        yAxisIndex: "none",
      },
      restore: {},
      saveAsImage: {},
    },
  },
  tooltip: {
    trigger: "axis",
    axisPointer: {
      type: "cross",
      animation: false,
      label: {
        backgroundColor: "#ccc",
        borderColor: "#aaa",
        borderWidth: 1,
        shadowBlur: 0,
        shadowOffsetX: 0,
        shadowOffsetY: 0,
        color: "#222",
      },
    },
  },
  legend: {
    data: ["灰度1", "灰度2", "灰度3", "灰度4", "灰度5", "人体1", "人体2", "人体3"],
  },
  dataZoom: [
    {
      show: true,
      realtime: true,
      start: 0,
      end: 100,
    },
    {
      type: "inside",
      realtime: true,
      start: 0,
      end: 100,
    },
  ],
  xAxis: {
    type: "category",
    data: xSerials,
    axisLabel: {
      formatter: "{value}s",
      align: "center",
    },
  },
  yAxis: {},
  series: [
    {
      name: "灰度1",
      type: "line",
      data: dataSensor1,
    },
    {
      name: "灰度2",
      type: "line",
      data: dataSensor2,
    },
    {
      name: "灰度3",
      type: "line",
      data: dataSensor3,
    },
    {
      name: "灰度4",
      type: "line",
      data: dataSensor4,
    },
    {
      name: "灰度5",
      type: "line",
      data: dataSensor5,
    },
    {
      name: "人体1",
      type: "line",
      data: dataSensor6,
    },
    {
      name: "人体2",
      type: "line",
      data: dataSensor7,
    },
    {
      name: "人体3",
      type: "line",
      data: dataSensor8,
    }
  ],
});
chart.setOption({
  animationDuration: 100,
  title: {
    text: "速度",
  },
  toolbox: {
    feature: {
      dataZoom: {
        yAxisIndex: "none",
      },
      restore: {},
      saveAsImage: {},
    },
  },
  tooltip: {
    trigger: "axis",
    axisPointer: {
      type: "cross",
      animation: false,
      label: {
        backgroundColor: "#ccc",
        borderColor: "#aaa",
        borderWidth: 1,
        shadowBlur: 0,
        shadowOffsetX: 0,
        shadowOffsetY: 0,
        color: "#222",
      },
    },
  },
  legend: {
    data: ["速度左", "速度右"],
  },
  dataZoom: [
    {
      show: true,
      realtime: true,
      start: 0,
      end: 100,
    },
    {
      type: "inside",
      realtime: true,
      start: 0,
      end: 100,
    },
  ],
  xAxis: {
    type: "category",
    data: xSerials,
    axisLabel: {
      formatter: "{value}s",
      align: "center",
    },
  },
  yAxis: {},
  series: [
    {
      name: "速度左",
      type: "line",
      data: dataSpeed1,
    },
    {
      name: "速度右",
      type: "line",
      data: dataSpeed2,
    },
  ],
});
updateChart();
fetch("/historyShort").then(r => r.json()).then(data => {
  for (var i = 0; i < data.length; i++) {
    addData(data[i], i == data.length - 1);
  }
});
setInterval(() => {
  fetch("/current").then(r => r.json()).then(data => {
    addData(data);
  });
}, 500);