import java.util.*;
class tic_tac_toe //suyash shukla
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Welcome to tic tac toe");
        System.out.println("For player one it is X and for player two it is O");
        int i=0,j=0,k=0,c=0;
        System.out.println("Position in game is given in followed oreder");
        for(i=0;i<3;i++)
        {
            System.out.println("______");
            for(j=0;j<3;j++)
            {
                c++;
                System.out.print(c+"|");
            }
            System.out.println("");
        }
        int ar[][]=new int[3][3];
        for(i=1;i<=9;i++)//loop for total chances
        { 
            System.out.println(" Enter the desired position for player 1 and 2");
            j=sc.nextInt();
            switch(j)//case for position
            {
                case 1:
                if(i%2==0)
                ar[0][0]=1;
                else
                ar[0][0]=2;
                break;
                case 2:
                 if(i%2==0)
                ar[0][1]=1;
                else
                ar[0][1]=2;
                break;
                case 3:
                 if(i%2==0)
                ar[0][2]=1;
                else
                ar[0][2]=2;
                break;
                case 4:
                 if(i%2==0)
                ar[1][0]=1;
                else
                ar[1][0]=2;
                break;
                case 5:
                 if(i%2==0)
                ar[1][1]=1;
                else
                ar[1][1]=2;
                break;
                case 6:
                 if(i%2==0)
                ar[1][2]=1;
                else
                ar[1][2]=2;
                break;
                case 7:
                 if(i%2==0)
                ar[2][0]=1;
                else
                ar[2][0]=2;
                break;
                case 8:
                 if(i%2==0)
                ar[2][1]=1;
                else
                ar[2][1]=2;
                break;
                case 9:
                 if(i%2==0)
                ar[2][2]=1;
                else
                ar[2][2]=2;
                break;
            }
        }
        for(i=0;i<3;i++)
        {
            System.out.println("______");
            for(k=0;k<3;k++)
             {
                if(ar[i][k]==1)
                System.out.print("X"+"|");
                else
                System.out.print("O"+"|");
            }
            System.out.println("");
        }
    }
}