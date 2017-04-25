
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MC_MANAGER_BASE_H

#define _CLASS_D3MC_MANAGER_BASE_H

#include <cassert>
#include <utility>

namespace D3MCS
{
	template<class ManagerType> class ManagerBase
	{
	private:
		static ManagerType *pInstance;

	protected:
		ManagerBase() = default;
		ManagerBase(const ManagerBase<ManagerType> &sSrc) = default;
		ManagerBase(ManagerBase<ManagerType> &&sSrc) = default;
		virtual ~ManagerBase() = default;

	protected:
		ManagerBase<ManagerType> &operator=(const ManagerBase<ManagerType> &sSrc) = default;
		ManagerBase<ManagerType> &operator=(ManagerBase<ManagerType> &&sSrc) = default;

	public:
		inline static ManagerType &instance();

		template<class ...ContructorParameter> static void initialize(ContructorParameter &&...sConstructorParam);
		static void finalize();
	};

	template<class ManagerType> inline ManagerType &ManagerBase<ManagerType>::instance()
	{
		assert(ManagerBase<ManagerType>::pInstance);

		return *ManagerBase<ManagerType>::pInstance;
	}
}

#include "ManagerBase.hpp"

#endif