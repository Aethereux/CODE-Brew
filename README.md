# Code Brew Ordering System

## Project Overview
Code Brew is a C++ based ordering system for a coffee shop. It allows users to select items from various categories, add them to a cart, and finalize their orders. The system also handles database operations to save and retrieve order data.

## Key Classes and Methods

### `MenuFunctions` Class
- **selectCategory**: Allows users to select a category of items.
- **selector**: Handles menu item selection.
- **arrowKeySelection**: Manages arrow key navigation.
- **order_or_TakeOut**: Allows users to choose between dine-in and take-out.

### `OrderFunctions` Class (inherits from `MenuFunctions`)
- **displayTotal**: Displays the total amount for the order.
- **checkOut**: Finalizes the order and processes payment.
- **addToCart**: Adds selected items to the cart.
- **deleteFromCart**: Removes items from the cart.
- **displayCart**: Displays the current cart contents.
- **createOrder**: Manages the entire order creation process.
- **addQuantity**: Allows users to specify the quantity of items.
- **getItemPrice**: Retrieves the price of an item.
- **displayMenu**: Displays the menu for a selected category.
- **saveOrderToDb**: Saves the order to the database.

### `Database` Class
- **absoluteRawFilePath**: Path to the raw orders file.
- **absolutePath**: Path to the processed orders file.
- **dataFromProgram**: Stores processed order data.

### `ReadDb` Class (inherits from `Database`)
- **readDb**: Reads raw order data from the file.
- **getOrderData**: Retrieves processed order data.

### `WriteDb` Class (inherits from `Database`)
- **addOrderToDb**: Writes raw order data to the file.
- **addDataToDb**: Writes processed order data to the file.
- **setDataFromProgram**: Sets the processed order data.

## Program Flow

1. **User Interaction**: The user interacts with the program through the `userui.cpp` interface.
2. **Order Creation**: The `OrderFunctions` class manages the order creation process, including item selection, quantity specification, and cart management.
3. **Database Operations**: The `ReadDb` and `WriteDb` classes handle reading from and writing to the database files to ensure order persistence.
4. **Checkout**: The user finalizes the order, and the program processes the payment and saves the order to the database.

## Example Usage

```cpp
int main () {
    OrderFunctions *order;
    while(true) {
        order = new OrderFunctions();
        order->createOrder();
        delete order;
    }
}