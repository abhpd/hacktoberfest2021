import java.util.Scanner;

class volume{
    public static void main(String[] arr){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter whoes volume you want to calculate(co/pri/cyl/sph/pyr/csa/tsac): ");
        // co-Cone ,pri-Prism,cyl-Cylinder,sph-Sphere,pyr-Pyramid,csa-Curved Surface Area Of Cylinder,tsac-Total Surface Area Of Cube
        
        String figer = scan.next();

        switch(figer){
            case "co":{
                System.out.println("Enter value of r and h:" );
                double r= scan.nextDouble();
                double h= scan.nextDouble();
                System.out.println("The volume of cone: "+ (0.3333)*(3.14*r*r*h));
                break;
            }
             case "pri":{
                System.out.println("Enter value of Base area and Height:" );
                int B= scan.nextInt();
                int H= scan.nextInt();
                System.out.println("The volume of prism: "+ (B*H));
                break;
            }
            case "cyl":{
                System.out.println("Enter value of radius and height:" );
                int r= scan.nextInt();
                int h= scan.nextInt();
                System.out.println("The volume of prism: "+ (h*3.14*r*r));
                break;
            }
             case "sph":{
                System.out.println("Enter value of radius:" );
                int r= scan.nextInt();
                System.out.println("The volume of Sphere: "+ ((1.3333*3.14)*(r*r*r)));
                break;
            }
            case "pyr":{
                System.out.println("Enter value of Base area and Height:" );
                int B= scan.nextInt();
                int H= scan.nextInt();
                System.out.println("The volume of pyramid: "+ (0.3333*(B*H)));
                break;
            }
            case "csa":{
                System.out.println("Enter value of r and h:" );
                int r= scan.nextInt();
                int h= scan.nextInt();
                System.out.println("The curved surface area of cylinder: "+ (2*3.14*r*h));
                break;
            }
            case "tsac":{
                System.out.println("Enter value of area of square(a):" );
                int a = scan.nextInt();
                System.out.println("The total surface area of cube: "+ (6*a*a));
                break;
            }
            default:{
                System.out.println("none");
                break;
            }
            
        
        }
    }
}
