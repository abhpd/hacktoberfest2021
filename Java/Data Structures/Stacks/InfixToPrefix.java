import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class InfixToPrefix {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();
    
        // code
        System.out.println(prefix(exp));
    }

    public static String prefix(String str){
        
        Stack<String> operand = new Stack<>();
        Stack<Character> operator = new Stack<>();
         
        for(int i=0 ; i<str.length() ; i++){
            
            char ch = str.charAt(i);

            if(ch == '('){
                operator.push(ch);
            }
            else if(ch == ')'){
                while(operator.peek() != '('){
                    char op = operator.pop();
                    String b = operand.pop();
                    String a = operand.pop();
                    operand.push(op+a+b);
                }
                operator.pop();
            }
            else if('a' <= ch && ch <= 'z'){
                operand.push(ch+"");
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                while(!operator.isEmpty() && operator.peek() != '(' && prec(ch) <= prec(operator.peek())){
                    char op = operator.pop();
                    String b = operand.pop();
                    String a = operand.pop();
                    operand.push(op+a+b);
                }
                operator.push(ch);
            }
        }

        while(!operator.isEmpty()){
            char op = operator.pop();
            String b = operand.pop();
            String a = operand.pop();
            operand.push(op+a+b);
        }
        return operand.peek();
    }

    public static int prec(char ch){
        if(ch == '*' || ch == '/'){
            return 2;
        }
        else{
            return 1;
        }
    }
}
