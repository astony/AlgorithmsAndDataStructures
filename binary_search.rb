#!/usr/bin/ruby

class BinarySearch

	attr_accessor :array
	attr_accessor :search_value

	def initialize(array, search_value)
		@array = array
		@search_value = search_value
	end

	def recursively(array = @array)
		# if array.size > 0
		# 	index = array.size / 2
		# 	if array[index] < @search_value
		# 		recursively array[index..-1]
		# 	elsif array[index] > @search_value
		# 		recursively array[0..index]
		# 	elsif array[index] == @search_value
		# 		index
		# 	end
		# else
		# 	-1
		# end
	end

	def iteratively
		p = 0
		k = @array.size
		while p <= k
			index = (p + k) / 2
			if @array[index] == @search_value
				index
			elsif @array[index] < @search_value
				k = index
			elsif @array[index] > @search_value
				p = index
			end
		end
	end

end

binary_search = BinarySearch.new [1,2,3,4,5,6,7,8,9], 6

thread_1 = Thread.new { puts "BinarySearch(#{binary_search.search_value}) in array #{binary_search.array} recursively: #{binary_search.recursively}" }
thread_2 = Thread.new { puts "BinarySearch(#{binary_search.search_value}) in array #{binary_search.array} iteratively: #{binary_search.iteratively}" }

thread_1.join
thread_2.join