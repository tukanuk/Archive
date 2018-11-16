/**
 * This class collects a pair of elements of different types 
 */
public class Pair<T, S>
{
	/* Private Instance Variables */
	private T first;
	private S second;

	/* Constructors */
	
	/**
	 *  Constructs a pair containing two given elements
	 *  @param firstElement the first element
	 *  @param secondElement the second element
	 */
	public Pair( T firstElement, S secondElement)
	{
		first = firstElement;
		second = secondElement;
	}

	/* Methods */

	/**
	 * Gets the first element in the pair
	 * @return the first element
	 */
	public T getFirst()
	{
		return first;
	}
	
	/**
	 * Gets the second element in the pair
	 * @return the second element
	 */
	public S getSecond()
	{
		return second;
	}

}
