<!DOCTYPE html>
<html>
<title>MPH to KPH Speed Converter</title>
<body>

<h2>Speed Unit Converter</h2>
<p>Type a value in the MPH field to convert the value to KPH:</p>

<p>
  <label>MPH</label>
  <input id="inputMPH" type="number" placeholder="MPH" oninput="speedConverter(this.value)" onchange="speedConverter(this.value)">
</p>
<p>KPH: <span id="outputKPH"></span></p>

<script>
function speedConverter(valNum) {
  document.getElementById("outputKPH").innerHTML=valNum*1.609344;
}
</script>

</body>
</html>
