package Array;
import java.util.*;
public class FirstRepited {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=0;
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
            if(m<a[i])
            m=a[i];
        }
        int b[]=new int[m+1];

        for(int i=0;i<n;i++)
        {
            if(b[a[i]]==0)
            b[a[i]]++;
            else
            {
                System.out.println(a[i]);
                break;
            }
        }
    }
    
}
