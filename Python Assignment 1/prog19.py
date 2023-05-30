prices={"AAA":25, "BBB":50000, "CCC": 5000,"DDD": 250,"EEE":800}

maxprice=max(prices.values())
minprice=min(prices.values())

sort_by_value=sorted(prices.items(),key=lambda item:item[1])

print(sort_by_value)

group=[]
for stock,price in prices.items():
	if price%500==0:
		group.append(stock)
print("Stock names that are multiple of 500")
print(group)


prices1={"prod1": 2000, "prod2":5000, "prod3": 400}

items1=prices.keys()
items2=prices.values()
fil=[]
for stock,price in prices1.items():
	if stock not in items1 and price not in items2:
		fil.append((stock,price))


print("Stock that are only in present first dictionary")
print(fil)


