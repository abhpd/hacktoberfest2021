const form = document.querySelector(".grocery-form");
const alert = document.querySelector(".alert");
const grocery = document.getElementById("grocery");
const submitBtn = document.querySelector(".submit-btn");
const container = document.querySelector(".grocery-container");
const list = document.querySelector(".grocery-list");
const clearBtn = document.querySelector(".clear-btn");

//edit option
let editElement;
let editFlag = false;
let editID = "";

form.addEventListener('submit', addItem);
clearBtn.addEventListener('click', clearItems);

function addItem(e){
    e.preventDefault();
    const value = grocery.value;
    const id = new Date().getTime().toString();
    
    if(value && !editFlag){
        const element = document.createElement('article');

        element.classList.add('grocery-item');

        const attr =document.createAttribute('data-id');
        attr.value = id;
        element.setAttributeNode(attr);

        element.innerHTML = `<p class="title">${value}</p>
        <div class="btn-container">
          <!-- edit btn -->
          <button type="button" class="edit-btn">
            <i class="fas fa-edit"></i>
          </button>
          <!-- delete btn -->
          <button type="button" class="delete-btn">
            <i class="fas fa-trash"></i>
          </button>
        </div>`;
        
        const deleteBtn = element.querySelector('.delete-btn');
        const editBtn = element.querySelector('.edit-btn');

        deleteBtn.addEventListener('click', deleteItem);
        editBtn.addEventListener('click', editItem);

        list.appendChild(element);

        displayAlert('Item added', 'success');

        container.classList.add('show-container');

        addToLocalStorage(id, value);

        setBackToDefault();
    }

    else if(value && editFlag){
        editElement.innerHTML = value;
        displayAlert('List Edited', 'success');
        
        editLocalStorage(editID,value);

        setBackToDefault(); 
    }

    else{
        displayAlert("Empty Value", "danger");
    };
};


function displayAlert(text, action){
    alert.textContent = text;
    alert.classList.add(`alert-${action}`);

    setTimeout(function(){
        alert.textContent = "";
        alert.classList.remove(`alert-${action}`);
    },1000);
}

function clearItems(){
    const items = document.querySelectorAll('.grocery-item');
    
        if(items.length > 0){
            items.forEach(function(item){
                list.removeChild(item);
            });
        }
    container.classList.remove('show-container');
    displayAlert('List Removed', 'danger');
    // localStorage.removeItem('list');
    setBackToDefault();
}

function deleteItem(e){
    const element = e.currentTarget.parentElement.parentElement;
    const id = element.dataset.id;
    list.removeChild(element);
    if (list.children.length === 0) {
        container.classList.remove('show-container');
    }

    displayAlert('Item deleted!','danger');
    setBackToDefault();

    // removeFromLocalStorage(id);
};

function editItem(e){
    const element = e.currentTarget.parentElement.parentElement;
    editElement = e.currentTarget.parentElement.previousElementSibling;
    
    grocery.value = editElement.innerHTML;
    editFlag = true;
    editID = element.dataset.id;
    submitBtn.textContent = "edit";
};

function setBackToDefault(){
    grocery.value = "";
    editFlag = false;
    editID = "";
    submitBtn.textContent = "submit"
}

function addToLocalStorage(id, value){
    console.log('Added to local storage');
}

function removeFromLocalStorage(id){
    
}

function editLocalStorage(id, value){
    
}