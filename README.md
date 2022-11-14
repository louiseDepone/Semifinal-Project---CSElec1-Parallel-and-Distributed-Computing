# Semifinal-Project---CSElec1-Parallel-and-Distributed-Computing
Semifinal Project for CSElec1 Parallel and Distributed Computing

Main Requirement: Write an algorithm and a C++ code simulating a queue in a supermarket.

Context: When customers have finalized their market cart, they shall then line up in the cashier lane to have their items scanned and ultimately be paid.

Assumptions:
There is only 1 cashier lane.
When a customer is now in his turn at the cashier checkpoint, it takes 0.5 unit time to take the item from the cart to the scanning table.
It also takes 0.5 unit time to scan the item.
It also takes 0.5 unit time to pack the item into a box or bag.
If a box is used, it takes 10 unit time to complete the packing.
If a bag is used, it takes only 5 unit time to complete the packing.
The scanning, packing, and package completion are not parallel.
When the customer is paying, it takes 20 unit time to pay by cash. If cash is exact, then it takes only 15 unit time.
When the customer is paying by card or via mobile payment app, it takes 15 unit time.
Receipt printing takes 0.3 unit time per scanned item to print, plus 2 unit time for other included text data.
There is also a 3 unit idle time after the previous customer completes, before the new customer will be processed.

Input File:
The input file shall contain a number of lines.
First line: Contains the number of customers on queue.
Succeeding line(s): Contains a space-separated data of:
   (a) number of items to be paid
   (b) the value `bag` or `box`, as the preferred packaging
   (c) the number of bags/boxes to be used
   (d) the value `cash` or `digital`, as the preferred payment method
   (e) the value `e` or `ne`, if payment method is cash, which means `exact` or `not exact`
