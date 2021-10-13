# awesome-cli-alerts
![📟](./.github/alerts.png)


[![📟](./.github/install.png)]
## Install

```sh
npm install awesome-cli-alerts
```

<br>
<img src="./.github/usage.png">

## Usage

```js
const alert = require('awesome-cli-alerts');

// provide the message type and msg
alert({type: 'success', msg: 'Everything\'s fine'});
// prints: ✔ SUCCESS Everything's fine

// provide the message type and msg
alert({type: 'success', msg: 'Everything\'s fine', name: 'DB'});
// prints: ✔ DB Everything's fine

alert({type: 'info', msg: 'I am new to Open Source!!'});
// Prints: ⚠ INFO I am new to Open Source!!


alert({type: 'warning', msg: 'You forgot something!'});
// Prints: ℹ INFO You forgot something!


alert({type: 'error', msg: 'Something went wrong!'});
// Prints: ✖ ERROR Something went wrong!



```
