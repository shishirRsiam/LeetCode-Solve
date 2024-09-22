select Customers.name as Customers from Customers
left join Orders on Customers.id = Orders.customerId
group by Customers.id having not count(Orders.customerId) or null;