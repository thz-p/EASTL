///////////////////////////////////////////////////////////////////////////////
// 版权声明
// 版权所有© Electronic Arts Inc. 保留所有权利。
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTL_UNORDERED_SET_H
#define EASTL_UNORDERED_SET_H

// 包含必要的头文件
#include <EASTL/internal/config.h>
#include <EASTL/hash_set.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once // 一些编译器（例如 VC++）会从中获益。我们通过测量已经证明在应用程序中可以提高 3-4% 的构建速度。
#endif

namespace eastl
{

	/// unordered_set 
	///
	/// 最初的 TR1（技术报告1）使用 "hash_set" 来命名一个基于哈希表的关联容器，用于存储唯一的 "Key" 类型对象。
	/// 当容器被添加到 C++11 标准中时，委员会选择了名字 "unordered_set" 来澄清内部元素不以任何特定顺序排序的事实。
	/// 我们在这里提供了一个模板别名，以确保与原始的 eastl::hash_set 具有相同的特性。
	///
	#if !defined(EA_COMPILER_NO_TEMPLATE_ALIASES)
		template <typename Value,
				  typename Hash = eastl::hash<Value>,
				  typename Predicate = eastl::equal_to<Value>,
				  typename Allocator = EASTLAllocatorType,
				  bool bCacheHashCode = false>
		using unordered_set = hash_set<Value, Hash, Predicate, Allocator, bCacheHashCode>;
	#endif

    /// unordered_multiset 
	///
	/// 类似于 "unordered_set" 的模板别名，但包含的元素不需要是唯一的。更多细节请参见 "hash_multiset"。
	///
	#if !defined(EA_COMPILER_NO_TEMPLATE_ALIASES)
		template <typename Value,
				  typename Hash = eastl::hash<Value>,
				  typename Predicate = eastl::equal_to<Value>,
				  typename Allocator = EASTLAllocatorType,
				  bool bCacheHashCode = false>
		using unordered_multiset = hash_multiset<Value, Hash, Predicate, Allocator, bCacheHashCode>;
	#endif

} // namespace eastl

#endif // Header include guard

// 这段代码是一个头文件，定义了两个模板别名 `unordered_set` 和 `unordered_multiset`，它们分别代表哈希集合和哈希多重集合。主要功能包括：

// 1. 提供对哈希集合和哈希多重集合的访问。
// 2. 允许用户指定自定义的哈希函数、比较函数和分配器。
// 3. 使用预处理指令防止重复包含，并使用 `#pragma once` 提高编译效率。

// 这样，用户在使用哈希集合和哈希多重集合时，可以通过这两个模板别名方便地进行访问和操作，同时也可以根据需要进行自定义参数配置。