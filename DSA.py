'''Trapping Rain Water Problem'''
# def find_total_water(arr,n):
#     total_water = 0
#     for i in range(1,n-1): #---O(n)  #ignoring the 1st and last index becausse we cannot have water at first and last index
#         left_max = max(arr[:i+1]) 
#         right_max = max(arr[i:]) 
#         total_water += min(left_max,right_max)-arr[i]
#     return total_water

# n = 3
# arr = [9,4,8]
# print(find_total_water(arr,n))
#-----------------------------------------------------------
'''Check for prime no.'''
# O(n)
# def isPrime(n):
#     for i in range(2,n+1):
#         if n%i==0:
#             return False
#     return True
# # O(n/2)--->O(n)
# def isPrime(n):
#     for i in range(2,1+(n//2)):
#         if n%i==0:
#             return False
#     return True
# # O(sqrt(n))
# def isPrime(n):
#     for i in range(2,int(pow(n,0.5)+1)):
#         if n%i==0:
#             return False
#     return True

# print(isPrime(34))
#-----------------------------------------------------------
''' Print all the prime numbers from 1 to n'''
# n = 100
# # O(n*sqrt(n))-->
# def printAllPrime(n):
#     for i in range(2,n+1): #O(n)
#         if isPrime(i): #O(sqrt(n))
#             print(i,end=" ")
# printAllPrime(n)
# Seive of eratosthenes
# def SieveOfEratosthenes(n):
#     prime = [True for i in range(n+1)]
#     i = 2
#     while (i * i <= n):
#         # If prime[i] is not changed, then it is a prime
#         if (prime[i] == True):
#             for j in range(i * i, n+1, i): # Update all multiples of i
#                 prime[j] = False
#         i += 1
    
#     for i in range(2, n+1): #O(n) Print all prime numbers
#         if prime[i]: #O(1)
#             print(i,end=" ")

# n = 30
# SieveOfEratosthenes(n)
# ----------------------------------------------------------

# printing all substrings of a given string
'''if len of string is n
    then total no. of substrings will bw (n*(n+1))//2'''
# def subString(s,n):
#     for Len in range(1,n + 1): # Pick starting point
#         for i in range(n - Len + 1): # Pick ending point
#             j = i + Len - 1
#             # Print characters from current starting point to current ending point.
#             for k in range(i,j + 1):
#                 print(s[k],end="")
#             print()
            
# # Driver program to test above function
# Str = "abc"
# subString(Str,len(Str))

# def subString(s, n):
#     for i in range(n):
#         for len in range(i+1,n+1):
#             print(s[i: len]);
#     # OR
#     for i in range(n):
#         temp=""
#         for j in range(i,n):
#             temp+=s[j]
#             print(temp)
 
# # Driver program to test above function
# s = "abcd"
# subString(s,len(s))
# ----------------------------------------------------------
''' Binary search'''
# time - O(logn), space: O(1)
# def binary_search(arr,n,x):
#     l=0
#     r=n-1
#     while(l<=r):
#         mid = (l+r)//2
#         if(arr[mid]==x):
#             return mid
#         elif(arr[mid]<x):
#             l = mid+1
#         else:
#             r = mid-1
#     return -1
# ==========================================================
