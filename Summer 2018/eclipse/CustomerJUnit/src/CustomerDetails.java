
public class CustomerDetails {
	
	private String name;
	private char gender;
	
	public CustomerDetails(){
		name = "Unknown";
		gender = 'x';
	}
	
	public CustomerDetails(String name, char gender){
		this.name = name;
		this.gender = gender;
	}
	
	public String getName(){
		return name;
	}
	public void setName(String name){
		this.name = name;
	}
	
	public char getGender(){
		return gender;
	}
	public void setGender(char gender){
		this.gender = gender;
	}
	
	public String toString(){
		if (gender == 'm'){
			return ("Name " + name + " - male");
			} 
		else if (gender == 'f'){
			return ("Name " + name + " - female");
			} 
		else 
			return ("Name and gender unknown");
	}
}