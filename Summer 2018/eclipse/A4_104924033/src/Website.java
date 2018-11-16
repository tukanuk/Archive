
public class Website 
{
	private String url;
	private ShoppingCart sc;
	
	public Website(String url)
	{
		this.setUrl(url);
		setSc(new ShoppingCart());
	}

	/**
	 * @return the url
	 */
	public String getUrl() {
		return url;
	}

	/**
	 * @param url the url to set
	 */
	public void setUrl(String url) {
		this.url = url;
	}

	/**
	 * @return the sc
	 */
	public ShoppingCart getSc() {
		return sc;
	}

	/**
	 * @param sc the sc to set
	 */
	public void setSc(ShoppingCart sc) {
		this.sc = sc;
	}
}
