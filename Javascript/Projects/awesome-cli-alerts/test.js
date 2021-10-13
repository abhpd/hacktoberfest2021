const alert = require('./alert.js');

// alert();

alert({
  type: `success`,
  msg: `Yeayy! DB Connected`,
  name: `DATABASE`
});
alert({
  type: `warning`,
  msg: `You're importing useEffect but not using it... `
});
alert({
  type: `error`,
  msg: `Get Request Failed`
});
alert({
  type: `info`,
  msg: `Your code can be optimized`
});
