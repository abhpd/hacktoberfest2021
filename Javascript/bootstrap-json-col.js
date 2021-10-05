// Edit before use
function loadJSONIntoDOMDynamically(file, id) {
    fetch(file)
        .then(response => response.json())
        .then(data => {
            const idLoad = document.querySelector('id')
            const elementsPerRow = 4
            let col = "col-md-3"
            let offset = ""
            if (data.length < 4) {
                switch(data.length) {
                    case 1:
                        col = "col-md-4"
                        offset = "offset-md-4";
                        break
                    case 2:
                        offset = "offset-md-3"
                        break
                }
            }
            let counter = 0
            let divReplacement = ""
            data.forEach(element => {
                if (counter != 0) offset = ""
                if (counter % elementsPerRow === 0) divReplacement += `<div class="row pb-3">`
                divReplacement +=
                `<div class="${col} ${offset} d-flex">
                        <h1>Content Here</h1>
                    </div>
                </div>`
                if (counter % elementsPerRow === elementsPerRow - 1) divReplacement += `</div>`
                counter++
            })
            idLoad.innerHTML = divReplacement
        })
}