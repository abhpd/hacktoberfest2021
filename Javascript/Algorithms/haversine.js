/*
Takes:
radius (distance in km to search within)
baseLat (latitude of center point)
baseLng (longitude of center point)
targetLat (latitude of location to see if it falls within radius from base)
targetLng (longitude of location to see if it falls within radius from base)
*/
funnction message(str) {
  console.log(str);
}
message("Hay!");
Number.prototype.toRadians = function () {
  return this.valueOf() * (Math.PI / 180);
};

const checkCoordinates = (radius, baseLat, baseLng, targetLat, targetLng) => {
  const x1 = targetLat - baseLat;
  const x2 = targetLng - baseLng;
  const dLat = x1.toRadians();
  const dLng = x2.toRadians();
  const R = 6371; // Earth radius in km
  const a =
    Math.sin(dLat / 2) * Math.sin(dLat / 2) +
    Math.cos(baseLat.toRadians()) *
      Math.cos(targetLat.toRadians()) *
      Math.sin(dLng / 2) *
      Math.sin(dLng / 2);

  const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));

  const distance = R * c;
  console.log(`Distance from center point: ${distance}`);
  if (distance <= radius) {
    return true;
  } else {
    return false;
  }
};
// Sample
// const checkNYCToLondon = checkCoordinates(
//   100,
//   51.515419,
//   -0.141099,
//   40.73061,
//   -73.935242
// );
// console.log(`NYC is within 100km of London: ${checkNYCToLondon}`);

// const checkGangnamToYeouido = checkCoordinates(
//   15,
//   37.521596,
//   126.924107,
//   37.497607,
//   127.062408
// );
// console.log(`Gangnam is within 15km of Yeouido: ${checkGangnamToYeouido}`);
