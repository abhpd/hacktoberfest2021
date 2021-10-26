module.exports.sleep = async (seconds) => {
  return await new Promise(resolve => setTimeout(resolve, seconds * 1000));
}
