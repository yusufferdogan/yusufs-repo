import java.util.NoSuchElementException;

public class GTUIterator<T> {
    private int index;
    private T[] arr;
    /**
     * constructor of the iterator
     * @param x Array of T
     */
    public GTUIterator(T[] x)
    {
        arr = x;
        index = 0;
    }

    /**
     * checks the iterator can iterate or not
     * @return true or false
     */
    public boolean hasNext()
    {
        if (arr.length - 1 > index)
        {
            return true;
        }
        return false;
    }

    /**
     *
     * @return the value at the index
     */

    public T get()
    {
        return arr[index];
    }

    /**
     *
     * @return the element at the index and increments the index
     * @throws NoSuchElementException if iterator can not iterate
     */
    public T next() throws NoSuchElementException
    {
        if (this.hasNext())
        {
            index++;
        }
        else {
            throw new NoSuchElementException("Iterator cannot iterate ");
        }
        return this.get();
    }
}
