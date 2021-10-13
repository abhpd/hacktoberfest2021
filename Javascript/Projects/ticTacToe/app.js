let status = document.querySelector('.status')
let reset = document.querySelector('.reset')
let cells = document.querySelectorAll('.game-cell')

//Weights of players
let playerOWeights = document.querySelectorAll('.player-o-weight')
let playerXWeights = document.querySelectorAll('.player-x-weight')

// Players Symbols
const xSymbol = '×'
const oSymbol = '○'

//Game Variables
let isGameLive = true
let isXNext = true

//Winner Declaration
const whoWon = (symbol) => {
    isGameLive = false
    if (symbol === 'x') {
        status.innerHTML = `<span>${xSymbol} has won!</span>`
    } else {
        status.innerHTML = `<span>${oSymbol} has won!</span>`
    }
}

//Checking Game Status After Every Click
const checkGameStatus = () => {
    const zeroZero = cells[0].classList[1]
    const zeroOne = cells[1].classList[1]
    const zeroTwo = cells[2].classList[1]
    const oneZero = cells[3].classList[1]
    const oneOne = cells[4].classList[1]
    const oneTwo = cells[5].classList[1]
    const twoZero = cells[6].classList[1]
    const twoOne = cells[7].classList[1]
    const twoTwo = cells[8].classList[1]

    //Checking Wining Conditions
    if (zeroZero && zeroZero === zeroOne && zeroOne === zeroTwo) {
        whoWon(zeroZero)
        cells[0].classList.add('won')
        cells[1].classList.add('won')
        cells[2].classList.add('won')
    } else if (oneZero && oneZero === oneOne && oneOne === oneTwo) {
        whoWon(oneZero)
        cells[3].classList.add('won')
        cells[4].classList.add('won')
        cells[5].classList.add('won')
    } else if (twoZero && twoZero === twoOne && twoOne === twoTwo) {
        whoWon(twoZero)
        cells[6].classList.add('won')
        cells[7].classList.add('won')
        cells[8].classList.add('won')
    } else if (zeroZero && zeroZero === oneZero && oneZero === twoZero) {
        whoWon(zeroZero)
        cells[0].classList.add('won')
        cells[3].classList.add('won')
        cells[6].classList.add('won')
    } else if (zeroOne && zeroOne === oneOne && oneOne === twoOne) {
        whoWon(zeroOne)
        cells[1].classList.add('won')
        cells[4].classList.add('won')
        cells[7].classList.add('won')
    } else if (zeroTwo && zeroTwo === oneTwo && oneTwo === twoTwo) {
        whoWon(zeroTwo)
        cells[2].classList.add('won')
        cells[5].classList.add('won')
        cells[8].classList.add('won')
    } else if (zeroZero && zeroZero === oneOne && oneOne === twoTwo) {
        whoWon(zeroZero)
        cells[0].classList.add('won')
        cells[4].classList.add('won')
        cells[8].classList.add('won')
    } else if (zeroTwo && zeroTwo === oneOne && oneOne === twoZero) {
        whoWon(zeroTwo)
        cells[2].classList.add('won')
        cells[4].classList.add('won')
        cells[6].classList.add('won')
    } else {
        isXNext = !isXNext
        if (isXNext) {
            status.innerHTML = `${xSymbol} is next`
        } else {
            status.innerHTML = `<span>${oSymbol} is next</span>`
        }
    }
}

//Reset Handler
const handleReset = () => {
    isXNext = true
    weightOfX = undefined
    weightOfO = undefined
    status.innerHTML = `${xSymbol} is next`
    for (const cell of cells) {
        cell.classList.remove('x')
        cell.classList.remove('o')
        cell.classList.remove('won')
        cell.innerText = 0
    }
    isGameLive = true
    let i = 1
    for (const playerXWeight of playerXWeights) {
        playerXWeight.innerText = i
        i++
    }
    let j = 6
    for (const playerOWeight of playerOWeights) {
        playerOWeight.innerText = j
        j--
    }
}

// Game Cell Handle
let weight
const handleCellClick = (e) => {
    weight = parseInt(e.target.innerText)
    const classList = e.target.classList
    if (!isGameLive ||
        (weightOfX === undefined && weightOfO === undefined) ||
        weightOfX <= weight ||
        weightOfO <= weight
    ) {
        return
    }
    if (isXNext) {
        classList.remove('o')
        classList.add('x')
        e.target.innerText = weightOfX
        weightOfX = undefined
        checkGameStatus()
    } else {
        classList.remove('x')
        classList.add('o')
        e.target.innerText = weightOfO
        weightOfO = undefined
        checkGameStatus()
    }
}

//Player's Weights Handle
let weightOfX = undefined
let weightOfO = undefined

const handlePlayerX = (e) => {
    if (isXNext && weightOfX === undefined) {
        if (e.target.innerText == 'X') {
            alert('Aleardy Used')
            return
        }
        weightOfX = parseInt(e.target.innerText)
        console.log(typeof weightOfX)
        e.target.innerText = 'X'
    }
}

const handlePlayerO = (e) => {
    if (!isXNext && weightOfO === undefined) {
        if (e.target.innerText == '0') {
            alert('Aleardy Used')
            return
        }
        weightOfO = parseInt(e.target.innerText)
        e.target.innerText = '0'
    }
}

//PlayerX Event Lisner
for (const playerXWeight of playerXWeights) {
    playerXWeight.addEventListener('click', handlePlayerX)
}
//PlayerO Event Lisner
for (const playerOWeight of playerOWeights) {
    playerOWeight.addEventListener('click', handlePlayerO)
}

//Event Listner Reset
reset.addEventListener('click', handleReset)

//Event Listner of Cellls
for (const cell of cells) {
    cell.addEventListener('click', handleCellClick)
}

//Modal Handle
let modal = document.querySelector('.modal')
let btn = document.querySelector('.rules')
let span = document.querySelector('.close')

const handleBtnClick = (e) => {
    modal.style.display = 'block'
}
const handleCloseClick = (e) => {
    modal.style.display = 'none'
}
btn.addEventListener('click', handleBtnClick)
span.addEventListener('click', handleCloseClick)