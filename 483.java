 class Solution
{
    public String smallestGoodBase(String n)
    {
        long N=Long.parseLong(n);
        double maxE= Math.log(N+1.0)/Math.log(2);
        int max=(int)maxE;
        long upper,x,y,m,res;
        java.math.BigInteger One=new java.math.BigInteger("1");
        java.math.BigInteger BigN=new java.math.BigInteger(n);
        for(int i=max;i>=2;i--)
        {
            upper=(long)Math.pow(N,2.0/i);
            x=2;y=upper;
            while(x<y)
            {
                m=(x+y)/2;
                java.math.BigInteger BigM=new java.math.BigInteger(String.valueOf(m));
                java.math.BigInteger temp=BigM.pow(i).add(One.negate()).divide(BigM.add(One.negate()));
                if(temp.compareTo(BigN)>0)
                {
                    y=m;
                }
                else if(temp.compareTo(BigN)<0)
                {
                    x=m+1;
                }
                else
                {
                    return String.valueOf(m);
                }
            }
            upper=x-1;
            x=2;y=upper+1;
            while(x<y)
            {
                m=(x+y)/2;
                if(2==i)
                    res=m+1;
                else
                {
                    java.math.BigInteger BigM=new java.math.BigInteger(String.valueOf(m));
                    java.math.BigInteger temp=BigM.pow(i).add(One.negate()).divide(BigM.add(One.negate()));
                    res=temp.longValue();
                }
                if(res<N)
                    x=m+1;
                else if(res>N)
                    y=m;
                else
                    return String.valueOf(m);
            }
        }
        return String.valueOf(Long.parseLong(n)-1);
    }
}
