import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class PostfixEvaluation {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();
    
        // code
        System.out.println(evaluate(exp));
    }

    public static int evaluate(String str){
        
        Stack<Integer> st = new Stack<>();

        for(int i=0 ; i<str.length() ; i++){

            char ch = str.charAt(i);

            if('0' <= ch && ch <= '9'){
                st.push(ch - '0');
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                int b = st.pop();
                int a = st.pop();
                st.push(solve(a,b,ch));
            }
        }
        return st.peek();
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
