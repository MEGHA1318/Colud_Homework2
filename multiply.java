import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;



//import com.sun.org.apache.xml.internal.resolver.helpers.PublicId;

public class Multiply
{ 
	public static void main(String[] args) 
	{ 
		Scanner scan = new Scanner(System.in);
		System.out.println("enter first Integer String");
    		String a=scan.next();
		System.out.println("enter second Integer String");
		String b=scan.next();
		ArrayList<String> L1 = new ArrayList<String>(); 

		L1.add(a); 

		ArrayList<String> L2 = new ArrayList<String>(); 

		L2.add(b); 
		
		multiply(L1, L2);
	} 

	static double multiply(ArrayList<String> L1, ArrayList<String> L2) 
	{ 
		String list1String = "", list2String = ""; 

		for(int i = 0; i < L1.size(); i++) 
			list1String += L1.get(i).toString(); 

		for(int i = 0; i < L2.size(); i++) 
			list2String += L2.get(i).toString(); 

		double Result=Double.parseDouble(list1String)*Double.parseDouble(list2String);

		//NumberFormat formatter=new DecimalFormat();

		System.out.println("Product of Strings: "+Result);

		return Result;
	} 
}
