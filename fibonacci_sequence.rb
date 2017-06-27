#!/usr/bin/ruby

class FibonacciSequence

	attr_accessor :n

	def initialize(n)
		@n = n
	end

	def recursively(n = @n)
		n == 1 || n == 2 ? 1 : recursively(n-1) + recursively(n-2)
	end

	def iteratively
		a = 1
		b = 1
		for i in 3..@n
			tmp = b
			b = a + b
			a = tmp
		end
		b
	end

end

fibonacci = FibonacciSequence.new 40

thread_1 = Thread.new { puts "Fibonacci(#{fibonacci.n}) recursively: #{fibonacci.recursively}" }
thread_2 = Thread.new { puts "Fibonacci(#{fibonacci.n}) iteratively: #{fibonacci.iteratively}" }

thread_1.join
thread_2.join