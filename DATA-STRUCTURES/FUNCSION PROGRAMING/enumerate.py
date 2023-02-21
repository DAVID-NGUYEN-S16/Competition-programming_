cuahang = ['banhmi', 'sua', 'keo']
enumerateCuahang = enumerate(cuahang)

print(type(enumerateCuahang))

# chuyển đổi thành một danh sách
# viết bởi Quantrimang.com
print(list(enumerateCuahang))

# bộ đếm chỉ định số bắt đầu
# viết bởi Quantrimang.com
enumerateCuahang = enumerate(cuahang, 10)
ls = list(enumerateCuahang)
print(ls[0][1])