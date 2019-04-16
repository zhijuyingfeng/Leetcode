
import java.util.LinkedHashMap;

class LRUCache 
{
    LinkedHashMap<Integer,Integer> m;
    int size,cap;

    public LRUCache(int capacity) 
    {
        m=new LinkedHashMap(capacity,(float)0.5,true);
        cap=capacity;
    }
    
    public int get(int key) 
    {
        if(!m.containsKey(key))
        {
            return -1;
        }
        return m.get(key);
    }
    
    public void put(int key, int value)
    {
        if(m.size()<cap)
        {
            m.put(key,value);
        }
        else
        {
            if(m.containsKey(key))
            {
                m.replace(key, value);
            }
            else
            {
                m.remove(m.keySet().iterator().next());
                m.put(key, value);
            }
        }
    }
    public static void main(String args[]) 
    {
//        System.out.println("hello world");
    }
}
