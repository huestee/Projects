const row = document.querySelector('.rm_carousel');
const movie = document.querySelectorAll('.carousel_movie');
const leftArrow = document.getElementById('left-arrow');
const rightArrow = document.getElementById('right-arrow');

// ----- ----- Event Listener (To Right Arrow) ----- -----
rightArrow.addEventListener('click', ()=>{
  //__ScrollLeft; does scroll to left.
  row.scrollLeft += row.offsetWidth; //__OffSetWidth; obtains contents width.
})

// ----- ----- Event Listener (To Left Arrow) ----- -----
leftArrow.addEventListener('click', ()=>{
  row.scrollLeft -= row.offsetWidth;
})

// ----- ----- Pagination ----- -----
/*conts numPage = Math.ceil(movie.length/5); //__Math.ceil; round to up.
for (let i = 0; i < numPage; i++) {
  const indicator = document.createElement('button');
  document.querySelector('.rm_indicators').appendChild(indicator);

  /*if(i==0){
    indicator.classList.add('.rm_indicators');
  }*/


// ----- -----  ----- -----
