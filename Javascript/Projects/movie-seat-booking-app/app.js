const containerEl = document.querySelector('.moviecontainer__middleMainSeats');
const seatsEl = document.querySelectorAll('.row .seat:not(.booked)');
const countEl = document.getElementById('count');
const totalEl = document.getElementById('total');
const selectEl = document.getElementById('movie');

let ticketPrice = selectEl.value;

// Getting Data from localstorage
getDataFromLocalStorage();
updateSelectedCount();

function getDataFromLocalStorage() {
  const selectedSeats = JSON.parse(localStorage.getItem('selectedSeats'));

  if (selectedSeats !== null && selectedSeats.length > 0) {
    seatsEl.forEach((seat, index) => {
      if (selectedSeats.indexOf(index) > -1) {
        seat.classList.add('selected');
      }
    });
  }

  const selectedMovieIndex = localStorage.getItem('selectedMovieIndex');

  if (selectedMovieIndex !== null) {
    const selectedEl = (selectEl.selectedIndex = selectedMovieIndex);
    ticketPrice = +selectEl[selectedEl].value;
  }
}

// Save selected movie index and price
function setMovieData(movieIndex, moviePrice) {
  localStorage.setItem('selectedMovieIndex', movieIndex);
  localStorage.setItem('selectedMoviePrice', moviePrice);
}

// Update Total and count
function updateSelectedCount() {
  const selectedSeats = document.querySelectorAll('.row .seat.selected');
  const selectedSeatsCount = selectedSeats.length;

  // 0. Saving data to local storage
  // 1. Copy selected seats into arr
  // 2. Map through array
  // 3. return a new array indexes

  const seatsIndex = [...selectedSeats].map((seat) => {
    return [...seatsEl].indexOf(seat);
  });

  localStorage.setItem('selectedSeats', JSON.stringify(seatsIndex));

  console.log(seatsIndex);

  countEl.innerText = selectedSeatsCount;
  totalEl.innerText = selectedSeatsCount * ticketPrice;
  // console.log(ticketPrice);
}

// Movie select event
selectEl.addEventListener('change', (e) => {
  ticketPrice = +e.target.value;
  setMovieData(e.target.selectedIndex, e.target.value);
  updateSelectedCount();
});

// Seat click event
containerEl.addEventListener('click', (e) => {
  if (
    e.target.parentElement.classList.contains('seat') &&
    !e.target.parentElement.classList.contains('booked') &&
    selectEl.value
  ) {
    e.target.parentElement.classList.toggle('selected');

    updateSelectedCount();

    return;
  }

  if (!selectEl.value) {
    alert('Please Select a movie');
  }
});
