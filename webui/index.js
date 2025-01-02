async function getValue(id) {
  return parseInt((await (await fetch(`/get-${id}`)).text()).split("\n").pop());
}
async function setValue(id, value) {
  await fetch(`/set-${id}`, { method: "POST", body: value })
}
const sensors = {
  "sensor-0": "LL",
  "sensor-1": "L",
  "sensor-2": "M",
  "sensor-3": "R",
  "sensor-4": "RR",
  "sensor-5": "SONIC",
  "any-31": "STAGE",
  "any-30": "PHASE",
  "any-29": "PAUSE",
};
const values = {
  "pid-0": "Kp",
  "pid-1": "Ki",
  "pid-2": "Kd",
  "speed-0": "Speed",
  "start-0": "Start",
  "any-16": "DELAY_START",
  "any-17": "PARAM_SONIC_THRESHOLD",
  "any-18": "PARAM_OBS_T1",
  "any-19": "PARAM_OBS_T2",
  "any-20": "PARAM_OBS_T3",
  "any-21": "PARAM_OBS_T4",
  "any-22": "PARAM_CIRCLE_T",
}
const sensorContainer = document.getElementById("sensors");
Object.keys(sensors).forEach(id => {
  const sensor = document.createElement("div");
  sensor.classList.add("sensor");
  sensor.classList.add("sv-container");
  sensor.innerHTML = `
    <div class="sensor-name">${sensors[id]}</div>
    <div class="sensor-value" id="sensor-${id}"></div>
  `;
  sensorContainer.appendChild(sensor);
});

const valueContainer = document.getElementById("values");
Object.keys(values).forEach(id => {
  const value = document.createElement("div");
  value.classList.add("value");
  value.classList.add("sv-container");
  value.innerHTML = `
    <div class="value-name">${values[id]}</div>
    <input type="number" class="value-input" id="value-${id}" oninput="this.classList.add('changed')"/>
    <button class="btn" onclick="setValue('${id}', document.getElementById('value-${id}').value);document.getElementById('value-${id}').classList.remove('changed');">Set</button>
  `;
  valueContainer.appendChild(value);
});
const controls = {
  "start": "Start",
  "pause": "Pause",
  "reset": "Reset"
}
Object.keys(controls).forEach(id => {
  const control = document.createElement("button");
  control.classList.add("btn");
  control.innerText = controls[id];
  control.onclick = async () => {
    await fetch(`/command`, { method: "POST", body: id });
  };
  valueContainer.appendChild(control);
});

async function updateSensors() {
  for (const id in sensors) {
    const sensor = document.getElementById(`sensor-${id}`);
    sensor.innerText = await getValue(id);
  }
  for (const id in values) {
    const value = document.getElementById(`value-${id}`);
    value.value = await getValue(id);
  }
  setTimeout(updateSensors, 1000);
}

updateSensors();