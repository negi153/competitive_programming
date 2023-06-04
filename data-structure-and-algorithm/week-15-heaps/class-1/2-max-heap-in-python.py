def heapify(nums,curr_index):
    n = len(nums)
    left = 2*curr_index
    right = 2*curr_index+1

    largest = curr_index

    if(left <n and nums[left] > nums[largest]):
        largest = left
    if(right < n and nums[right] > nums[largest]):
        largest = right

    if(largest != curr_index):
      nums[curr_index],nums[largest] = nums[largest],nums[curr_index]
      heapify(nums,largest)

def get_top_3(nums):
    for i in range(len(nums)-1,1,-1):
        heapify(nums,i)
    # print('after first heapify - ',nums)
    # return
    # get top 3
    ans = []
    for i in range(1,4):
        ans.append(nums[1])
        t = nums[1]
        nums[1] = nums[-1]
        nums.pop()
        heapify(nums,1)
        # print('after deliting - ',t,'->',nums)

    print(ans)
    


get_top_3([-1,100,56,89,91])