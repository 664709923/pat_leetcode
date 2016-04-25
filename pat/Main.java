import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String a,b,c;
		int n;
		n=sc.nextInt();
		for(int i=1;i<=n;i++){
			a=sc.next();
			b=sc.next();
			c=sc.next();
			BigInteger ba = new BigInteger(a);
			BigInteger bb = new BigInteger(b);
			BigInteger bc = new BigInteger(c);
			if(ba.add(bb).compareTo(bc)>0){
				System.out.println("Case #"+i+": true");
			}else{
				System.out.println("Case #"+i+": false");
			}

		}
		
	}

}

