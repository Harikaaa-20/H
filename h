import java.util.*;

// Class representing the Inventory of the SmartGrocery platform
class Inventory {
    private Map<String, Integer> stock;
    private Map<String, Double> prices;

    public Inventory() {
        stock = new HashMap<>();
        prices = new HashMap<>();

        // Expanded stock initialization with prices, including a mix of multi-cuisine and Indian ingredients
        stock.put("Almonds", 50);
        prices.put("Almonds", 400.0); // in INR

        stock.put("Basil", 100);
        prices.put("Basil", 150.0); 

        stock.put("Carrot", 80);
        prices.put("Carrot", 50.0);

        stock.put("Chicken", 75);
        prices.put("Chicken", 350.0);

        stock.put("Cheese", 120);
        prices.put("Cheese", 250.0);

        stock.put("Cucumber", 60);
        prices.put("Cucumber", 40.0);

        stock.put("Eggs", 200);
        prices.put("Eggs", 6.0);

        stock.put("Fish", 70);
        prices.put("Fish", 500.0);

        stock.put("Garlic", 100);
        prices.put("Garlic", 80.0);

        stock.put("Honey", 90);
        prices.put("Honey", 300.0);

        stock.put("Iceberg Lettuce", 30);
        prices.put("Iceberg Lettuce", 150.0);

        stock.put("Jalapeno", 40);
        prices.put("Jalapeno", 200.0);

        stock.put("Kale", 30);
        prices.put("Kale", 100.0);

        stock.put("Lemon", 80);
        prices.put("Lemon", 20.0);

        stock.put("Mushrooms", 100);
        prices.put("Mushrooms", 250.0);

        stock.put("Nuts", 60);
        prices.put("Nuts", 600.0);

        stock.put("Onion", 150);
        prices.put("Onion", 50.0);

        stock.put("Olive Oil", 120);
        prices.put("Olive Oil", 1000.0);

        stock.put("Paprika", 90);
        prices.put("Paprika", 100.0);

        stock.put("Potato", 200);
        prices.put("Potato", 40.0);

        stock.put("Quinoa", 100);
        prices.put("Quinoa", 400.0);

        stock.put("Rice", 300);
        prices.put("Rice", 70.0);

        stock.put("Salmon", 40);
        prices.put("Salmon", 800.0);

        stock.put("Tomato", 120);
        prices.put("Tomato", 30.0);

        stock.put("Udon Noodles", 50);
        prices.put("Udon Noodles", 300.0);

        stock.put("Vinegar", 60);
        prices.put("Vinegar", 150.0);

        stock.put("Walnuts", 80);
        prices.put("Walnuts", 800.0);

        stock.put("Xanthan Gum", 30);
        prices.put("Xanthan Gum", 1000.0);

        stock.put("Yogurt", 70);
        prices.put("Yogurt", 50.0);

        stock.put("Zucchini", 60);
        prices.put("Zucchini", 80.0);

        // Additional Indian Ingredients
        stock.put("Atta", 200); // Wheat flour
        prices.put("Atta", 45.0);

        stock.put("Ghee", 100);
        prices.put("Ghee", 600.0);

        stock.put("Turmeric", 90);
        prices.put("Turmeric", 200.0);

        stock.put("Paneer", 120);
        prices.put("Paneer", 300.0);

        stock.put("Masoor Dal", 150);
        prices.put("Masoor Dal", 100.0);

        stock.put("Basmati Rice", 200);
        prices.put("Basmati Rice", 150.0);

        stock.put("Mustard Seeds", 100);
        prices.put("Mustard Seeds", 120.0);

        stock.put("Coriander", 100);
        prices.put("Coriander", 50.0);

        stock.put("Tamarind", 100);
        prices.put("Tamarind", 70.0);

        stock.put("Fenugreek", 90);
        prices.put("Fenugreek", 80.0);

        // Additional multi-cuisine ingredients
        stock.put("Soy Sauce", 80);
        prices.put("Soy Sauce", 180.0);

        stock.put("Sriracha", 70);
        prices.put("Sriracha", 250.0);

        stock.put("Pasta", 150);
        prices.put("Pasta", 200.0);

        stock.put("Coconut Milk", 80);
        prices.put("Coconut Milk", 300.0);

        stock.put("Chili Powder", 90);
        prices.put("Chili Powder", 100.0);
    }

    public boolean isAvailable(String item, int quantity) {
        return stock.getOrDefault(item, 0) >= quantity;
    }

    public void updateStock(String item, int quantity) {
        if (isAvailable(item, quantity)) {
            stock.put(item, stock.get(item) - quantity);
            System.out.println(quantity + " units of " + item + " purchased. Remaining stock: " + stock.get(item));
        } else {
            System.out.println("Sorry, not enough stock for " + item);
        }
    }

    public double getPrice(String item) {
        return prices.getOrDefault(item, 0.0);
    }

    public void displayStock() {
        System.out.println("Available Inventory: " + stock);
    }
}

// Class representing a User of the SmartGrocery platform
class User {
    private String name;
    private double balance;
    private List<String> purchaseHistory;

    public User(String name, double balance) {
        this.name = name;
        this.balance = balance;
        this.purchaseHistory = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public boolean makePayment(double amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Payment of ₹" + amount + " successful. Remaining balance: ₹" + balance);
            return true;
        } else {
            System.out.println("Insufficient balance.");
            return false;
        }
    }

    public void addPurchase(String item, int quantity) {
        purchaseHistory.add(item + " x" + quantity);
    }

    public void showPurchaseHistory() {
        System.out.println("Purchase History for " + name + ": " + purchaseHistory);
    }
}

// Class representing a Dish and its ingredients
class Dish {
    private String name;
    private List<String> ingredients;

    public Dish(String name, List<String> ingredients) {
        this.name = name;
        this.ingredients = ingredients;
    }

    public void showIngredients() {
        System.out.println("Ingredients for " + name + ": " + ingredients);
    }

    public List<String> getIngredients() {
        return ingredients;
    }

    public String getName() {
        return name;
    }
}

// Main class for SmartGrocery
public class SmartGrocery {
    private static List<User> users = new ArrayList<>();
    private static List<Dish> dishes = new ArrayList<>();
    private static Inventory inventory = new Inventory();

    public static void main(String[] args) {
        // Initialize some users
        users.add(new User("Aarav", 5000.0));
        users.add(new User("Diya", 3000.0));

        // Initialize dishes with a mix of Indian and multi-cuisine options
        dishes.add(new Dish("Paneer Butter Masala", Arrays.asList("Paneer", "Tomato", "Onion", "Ghee")));
        dishes.add(new Dish("Dal Tadka", Arrays.asList("Masoor Dal", "Tomato", "Garlic", "Ghee")));
        dishes.add(new Dish("Chicken Biryani", Arrays.asList("Chicken", "Basmati Rice", "Onion", "Garlic")));
        dishes.add(new Dish("Rajma Chawal", Arrays.asList("Rajma", "Onion", "Tomato", "Garlic", "Basmati Rice")));
        dishes.add(new Dish("Aloo Paratha", Arrays.asList("Atta", "Potato", "Onion", "Ghee")));
        dishes.add(new Dish("Dosa", Arrays.asList("Rice", "Urad Dal", "Onion", "Ghee")));
        dishes.add(new Dish("Samosa", Arrays.asList("Flour", "Potato", "Peas", "Ghee", "Onion")));
        dishes.add(new Dish("Palak Paneer", Arrays.asList("Paneer", "Spinach", "Onion", "Ghee")));
        dishes.add(new Dish("Idli Sambar", Arrays.asList("Rice", "Urad Dal", "Sambar Masala", "Tamarind")));
        dishes.add(new Dish("Chicken Tikka", Arrays.asList("Chicken", "Yogurt", "Garlic", "Ginger")));

        // Additional Indian dishes
        dishes.add(new Dish("Chole Bhature", Arrays.asList("Chickpeas", "Atta", "Onion", "Tomato", "Ghee")));
        dishes.add(new Dish("Butter Chicken", Arrays.asList("Chicken", "Tomato", "Cream", "Butter", "Garlic")));
        dishes.add(new Dish("Pani Puri", Arrays.asList("Semolina", "Potato", "Chickpeas", "Tamarind")));
        dishes.add(new Dish("Bhindi Masala", Arrays.asList("Okra", "Onion", "Tomato", "Spices")));
        dishes.add(new Dish("Aloo Gobi", Arrays.asList("Potato", "Cauliflower", "Onion", "Spices")));
        dishes.add(new Dish("Kachori", Arrays.asList("Flour", "Lentils", "Spices", "Oil")));
        dishes.add(new Dish("Pulao", Arrays.asList("Rice", "Vegetables", "Spices", "Ghee")));
        dishes.add(new Dish("Kheer", Arrays.asList("Rice", "Milk", "Sugar", "Cardamom")));
        dishes.add(new Dish("Rogan Josh", Arrays.asList("Lamb", "Yogurt", "Tomato", "Spices")));
        dishes.add(new Dish("Dhokla", Arrays.asList("Rice Flour", "Chickpea Flour", "Yogurt", "Spices")));
        dishes.add(new Dish("Pakora", Arrays.asList("Chickpea Flour", "Vegetables", "Spices", "Oil")));

        // Multi-cuisine dishes
        dishes.add(new Dish("Spaghetti Carbonara", Arrays.asList("Pasta", "Eggs", "Cheese", "Bacon")));
        dishes.add(new Dish("Sushi", Arrays.asList("Rice", "Seaweed", "Fish", "Vegetables")));
        dishes.add(new Dish("Tacos", Arrays.asList("Tortillas", "Ground Beef", "Cheese", "Lettuce")));
        dishes.add(new Dish("Beef Stroganoff", Arrays.asList("Beef", "Mushrooms", "Onion", "Cream")));
        dishes.add(new Dish("Falafel", Arrays.asList("Chickpeas", "Garlic", "Spices", "Oil")));
        dishes.add(new Dish("Paella", Arrays.asList("Rice", "Seafood", "Vegetables", "Saffron")));
        dishes.add(new Dish("Greek Salad", Arrays.asList("Tomato", "Cucumber", "Olives", "Feta Cheese")));
        dishes.add(new Dish("Chow Mein", Arrays.asList("Noodles", "Vegetables", "Soy Sauce", "Chicken")));
        dishes.add(new Dish("Tom Yum Soup", Arrays.asList("Shrimp", "Lemongrass", "Chili", "Lime Juice")));
        dishes.add(new Dish("Beef Wellington", Arrays.asList("Beef", "Puff Pastry", "Mushrooms", "Prosciutto")));
        dishes.add(new Dish("Chicken Adobo", Arrays.asList("Chicken", "Soy Sauce", "Vinegar", "Garlic")));

        // More dishes to reach around 60 total
        dishes.add(new Dish("Moussaka", Arrays.asList("Eggplant", "Ground Beef", "Tomato", "Bechamel")));
        dishes.add(new Dish("Ratatouille", Arrays.asList("Eggplant", "Zucchini", "Tomato", "Bell Peppers")));
        dishes.add(new Dish("Bangers and Mash", Arrays.asList("Sausages", "Potatoes", "Onion", "Gravy")));
        dishes.add(new Dish("Ceviche", Arrays.asList("Fish", "Lime Juice", "Onion", "Cilantro")));
        dishes.add(new Dish("Banh Mi", Arrays.asList("Baguette", "Pork", "Pickled Vegetables", "Cilantro")));
        dishes.add(new Dish("Pad Thai", Arrays.asList("Rice Noodles", "Shrimp", "Peanuts", "Bean Sprouts")));
        dishes.add(new Dish("Katsu Curry", Arrays.asList("Chicken", "Rice", "Curry Sauce", "Panko")));
        dishes.add(new Dish("Kimchi Fried Rice", Arrays.asList("Rice", "Kimchi", "Pork", "Egg")));
        dishes.add(new Dish("Goulash", Arrays.asList("Beef", "Paprika", "Onion", "Potato")));
        dishes.add(new Dish("Couscous", Arrays.asList("Couscous", "Vegetables", "Spices", "Olive Oil")));
        dishes.add(new Dish("Fried Rice", Arrays.asList("Rice", "Vegetables", "Soy Sauce", "Egg")));
        dishes.add(new Dish("Lamb Tagine", Arrays.asList("Lamb", "Apricots", "Almonds", "Spices")));
        dishes.add(new Dish("Lasagna", Arrays.asList("Pasta Sheets", "Ground Beef", "Cheese", "Tomato Sauce")));
        dishes.add(new Dish("Chili Con Carne", Arrays.asList("Ground Beef", "Beans", "Tomatoes", "Spices")));

        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to SmartGrocery!");

        for (User user : users) {
            System.out.println("\n" + user.getName() + "'s turn to shop.");
            inventory.displayStock();
            System.out.println("Enter the dish you want to cook:");
            String dishName = scanner.nextLine();
            Dish selectedDish = searchDish(dishName);

            if (selectedDish != null) {
                selectedDish.showIngredients();
                System.out.println("Do you want to purchase ingredients? (yes/no)");
                String response = scanner.nextLine();

                if ("yes".equalsIgnoreCase(response)) {
                    double totalCost = 0;
                    for (String ingredient : selectedDish.getIngredients()) {
                        if (inventory.isAvailable(ingredient, 1)) {
                            double price = inventory.getPrice(ingredient);
                            totalCost += price;
                            inventory.updateStock(ingredient, 1);
                            user.addPurchase(ingredient, 1);
                        } else {
                            System.out.println("Ingredient " + ingredient + " is out of stock.");
                        }
                    }
                    if (user.makePayment(totalCost)) {
                        System.out.println("Total cost: ₹" + totalCost);
                        user.showPurchaseHistory();
                    } else {
                        System.out.println("Transaction failed.");
                    }
                } else {
                    System.out.println("No ingredients purchased.");
                }
            } else {
                System.out.println("Dish not found.");
            }
        }
    }

    private static Dish searchDish(String dishName) {
        for (Dish dish : dishes) {
            if (dish.getName().equalsIgnoreCase(dishName)) {
                return dish;
            }
        }
        return null;
    }
}
