package com.company;

import java.util.Stack;

public class BalancedParanthesisProblem {
    public static boolean matching(char a, char b){
        return ((a=='(') && b==')') ||(a=='[' && b==']')|| (a=='{' && b=='}');
    }

    public static boolean isBalanced(String str){
        Stack<Character> s = new Stack<Character>();

        for (int i=0;i<str.length();i++){
            if (str.charAt(i)=='(' || str.charAt(i)=='[' || str.charAt(i)=='{'){
                s.add(str.charAt(i));
            }else {
                if (s.isEmpty()){
                    return false;
                }else if (!matching(s.peek(), str.charAt(i))){
                    return false;
                }else {
                    s.pop();
                }

            }
        }
        return (s.isEmpty());
    }
    public static void main(String[] args) {
        String str = "{()}[]";

        if (isBalanced(str)){
            System.out.println("Balanced");
        }else {
            System.out.println("Not balanced");
        }
    }
}
