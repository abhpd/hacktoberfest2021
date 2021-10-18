import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class InfixEvaluation {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();
    
        // code
        System.out.println(evaluate(exp));
     }

    public static int evaluate(String str){

        Stack<Integer> operand = new Stack<>();
        Stack<Character> operator = new Stack<>();
         
        for(int i=0 ; i<str.length() ; i++){
            
            char ch = str.charAt(i);

            if(ch == '('){
                operator.push(ch);
            }
            else if(ch == ')'){
                while(operator.peek() != '('){
                    char op = operator.pop();
                    int b = operand.pop();
                    int a = operand.pop();
                    operand.push(solve(a,b,op));
                }
                operator.pop();
            }
            else if('0' <= ch && ch <= '9'){
                operand.push(ch - '0');
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                while(!operator.isEmpty() && operator.peek() != '(' && prec(ch) <= prec(operator.peek())){
                    char op = operator.pop();
                    int b = operand.pop();
                    int a = operand.pop();
                    operand.push(solve(a,b,op));
                }
                operator.push(ch);
            }
        }

        while(!operator.isEmpty()){
            char op = operator.pop();
            int b = operand.pop();
            int a = operand.pop();
            operand.push(solve(a,b,op));
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

    public static int solve(int a,int b,int op){
        if(op == '*'){
            return a*b;
        }
        else if(op == '/'){
            return a/b;
        }
        else if(op == '+'){
            return a+b;
        }
        else{
            return a-b;
        }
    }
}
