/**
 * Implementation of GtuContainer Abstract class functions
 *
 * @author Ahmet yusuf erdoğan
 * @version 1.0
 * @since 2020-01-17
 */
public class GTUVector<T> extends GTUContainer<T> {
    private T[] arr;
    private static final int max_size = 999;

    /**
     * the constructor of the class
     * @param arr is the array of T
     */
    public GTUVector(T[] arr)
    {
        this.arr = arr;
    }

    /**
     *
     * @return new iterator
     */
    @Override
    public GTUIterator<T> iterator()
    {
        return new GTUIterator<>(arr);
    }

    /**
     *
     * @return boolean of vector is empty or not
     */
    @Override
    public boolean empty()
    {
        return size() <= 0;
    }

    /**
     *
     * @return size of the array
     */
    @Override
    public int size()
    {
        if (null == arr)
        {
            return 0;
        }
        return arr.length;
    }

    /**
     * @return max_size
     */
    @Override
    public int max_size()
    {
        return max_size;
    }

    /**
     * @param arr is the array
     * @param key is the searching value
     * @return key is found in the array or not
     */
    public boolean isFound(T[] arr,T key)
    {
        for (int x = 0; x < arr.length; x++) {
            if (this.arr[x].equals(key)) {
                return true;
            }
        }
        return false;
    }

    /**
     *
     * @param arr is the array
     * @param key is the searching value
     * @return key value's index
     */
    public int indexof(T[] arr,T key)
    {
        for (int x = 0; x < arr.length; x++) {
            if (this.arr[x].equals(key)) {
                return x;
            }
        }
        return 0;
    }

    /**
     * deleting
     * @param element
     * from the vector
     */
    @SuppressWarnings("unchecked")
    @Override
    public void erase(T element) {
        T[] newArr = (T[]) new Object[arr.length - 1];
        if (isFound(arr, element)){
            int pos = indexof(arr, element);
            if (pos > 0) {
                for (int j = 0; j < pos; j++) {
                    newArr[j] = arr[j];
                }
                for (int i = pos; i < arr.length - 1; i++) {
                    newArr[i] = arr[i + 1];
                }
            }
            else if(pos == 0)
            {
                for (int i = pos; i < arr.length - 1; i++) {
                    newArr[i] = arr[i + 1];
                }
            }
            arr = newArr;
            System.out.println("element : " + element + " erased ");

        }
        else {
            System.out.println("element : " + element + " is not in array. Erase failed");
        }
    }
    /**
     * delete all the elements in the vector
     */
    @Override
    public void clear() {
        T[] newArr = (T[])new Object[0];
        arr = newArr;
    }
    /**
     * checks if Arr contains
     * @param element
     */
    @Override
    public boolean contains(T element) {
        for (int i = 0; i < this.size(); i++)
        {
            if (this.arr[i].equals(element))
            {
                return true;
            }
        }
        return false;
    }
    /**
     * @param t The element
     * inserting element to the vector
     */
    @Override
    public void insert(T t)
    {
        T[] newArr = (T[])new Object[this.size() + 1];
        if (this.size() > 0) {
            System.arraycopy(this.arr, 0, newArr, 0, this.size());
        }
        newArr[this.size()] = t;
        arr = newArr;
        System.out.println("element insterted : " + t);
    }
    /**
     * printing elements of the vector
     */
    public void Print(){
        System.out.print("GtuSet{arr=[");
        for (int i = 0;i < size() ; i++){
            System.out.print(arr[i] + " ,");
        }
        System.out.print("]");
        System.out.println("}");
    }
}
