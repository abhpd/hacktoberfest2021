const data = ['Ali','Ahmad','John','Kayle','Jerry','Jasmine']

const data_to_be_search = 'Kayle'

// Linear Searching
for ( i = 0 ; i < data.length ; i++ ) {
  if ( data[i] === data_to_be_search ) {
    console.log("Data Found at index",  i)
    break;
  }
}
