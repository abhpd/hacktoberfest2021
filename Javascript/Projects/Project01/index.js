var addButton = document.getElementById("addTodo");
var removeButton = document.getElementById("removeTodo");
ul = document.getElementById("list");
var li;
addButton.addEventListener("click", addItem);
removeButton.addEventListener("click", removeItem);
function addItem() {
  var input = document.getElementById("input");
  var item = input.value;
  ul = document.getElementById("list");
  var textnode = document.createTextNode(item);

  if (item === "") {
    // document.getElementById("message").textContent = "Enter todo";
    var message = document.createElement("p");
    message.textContent = "Enter Todo";
    var con = document.getElementById("controls");
    con.appendChild(message);
    return false;
  } else {
  }
}
function removeItem() {
  li = ul.children;
  for (let i = 0; i < li.length; i++) {
    while (li[i] && li[i].children[0].checked) {
      ul.removeChild(li[i]);
    }
  }
}
