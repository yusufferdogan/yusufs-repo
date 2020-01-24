/**
 * GtuContainer Abstract class functions
 *
 * @author Ahmet yusuf erdoğan
 * @version 1.0
 * @since 2020-01-17
 */
public abstract class GTUContainer<T> {
    public abstract GTUIterator<T> iterator();
    public abstract boolean empty();
    public abstract int     size();
    public abstract int     max_size();
    public abstract void    erase(T t);
    public abstract void    clear();
    public abstract boolean contains(T t);
    public abstract void    insert(T t);

}
