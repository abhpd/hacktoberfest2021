/**
 * UUID V4
 *
 * @returns {string} uuid
 */
function uuidv4() {
  const pattern = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";

  return pattern.replace(/[xy]/g, (char) => {
    const x = (Math.random() * 16) | 0;
    const value = char == "x" ? x : (x & 0x3) | 0x8;
    return value.toString(16);
  });
}

const uuid = uuidv4();

/* eslint-disable no-console */
console.log("uuid", uuid);
console.log("uuid:length", [...uuid].length === 36);
/* eslint-enable no-console */
