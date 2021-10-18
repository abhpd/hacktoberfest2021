import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class InfixToPostfix {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();
    
        // code
        postfix1(exp);
        System.out.println(postfix2(exp));
    }

    ///////////// USING 2 STACKS ///////////////////
    public static String postfix2(String str){

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
                    operand.push(a+b+op);
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
                    operand.push(a+b+op);
                }
                operator.push(ch);
            }
        }

        while(!operator.isEmpty()){
            char op = operator.pop();
            String b = operand.pop();
            String a = operand.pop();
            operand.push(a+b+op);
        }
        return operand.peek();
    }

    ////////////// USING 1 STACK ////////////////
    public static void postfix1(String str){

        Stack<Character> operator = new Stack<>();
         
        for(int i=0 ; i<str.length() ; i++){
            
            char ch = str.charAt(i);

            if(ch == '('){
                operator.push(ch);
            }
            else if(ch == ')'){
                while(operator.peek() != '('){
                    System.out.print(operator.pop());
                }
                operator.pop();
            }
            else if('a' <= ch && ch <= 'z'){
                System.out.print(ch);
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                while(!operator.isEmpty() && operator.peek() != '(' && prec(ch) <= prec(operator.peek())){
                    System.out.print(operator.pop());
                }
                operator.push(ch);
            }
        }

        while(!operator.isEmpty()){
            System.out.print(operator.pop());
        }
        return;
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
