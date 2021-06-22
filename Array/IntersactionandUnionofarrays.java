package Array;

import java.util.*;

import javax.lang.model.util.ElementScanner6;
public class IntersactionandUnionofarrays {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int a[]=new int[n];
        int b[]=new int[m];
        for(int i=0;i<n;i++)a[i]=sc.nextInt();
        for(int i=0;i<m;i++)b[i]=sc.nextInt();
        Arrays.sort(a);
        Arrays.sort(b);
        int j=0,i=0;
        System.out.print("Intersaction\n");
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                System.out.print(a[i]+" ");
                i++;j++;
            }
            else if(a[i]<b[i])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        j=0;i=0;
        System.out.print("\nUnion\n");
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                System.out.print(a[i]+" ");
                i++;j++;
            }
            else if(a[i]<b[i])
            {
                System.out.print(a[i]+" ");
                i++;
            }
            else
            {
                System.out.print(b[j]+" ");
                j++;
            }
        }
        while(i<n)
        {
            System.out.print(a[i]+" ");
            i++; 
        }
        while(j<m)
        {
            System.out.print(b[j]+" ");
            j++; 
        }
    }}