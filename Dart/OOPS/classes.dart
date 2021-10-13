
class Students{
  var _name;
  var _age;
  var _rollNo;
  Students(name,age,rollNo){
    this._name = name;
    this._age = age;
    this._rollNo = rollNo;
  }
  
  String get getData{
    return ("Name is :- "+_name.toString()+"\nAge is :- "+_age.toString()+"\nRoll No :- "+_rollNo.toString());
  }
  
}

void main() {
  Students std = Students("Saumil",20,36);
  print(std.getData);
}
