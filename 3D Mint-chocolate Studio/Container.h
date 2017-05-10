
/*
	2017.04.28
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UTILITY_CONTAINER_H

#define _CLASS_D3MCS_UTILITY_CONTAINER_H

#include <cstdint>
#include <utility>

namespace D3MCS::Utility
{
	template<class LoadType> class Container final
	{
	private:
		bool bLoaded;
		uint8_t vLoad[sizeof(LoadType)];
		
	public:
		Container();
		template<class ...ContructorParameter> Container(ContructorParameter &&...sConstructorParam);
		Container(const Container<LoadType> &sSrc);
		Container(Container<LoadType> &&sSrc);
		~Container();
		
	public:
		Container<LoadType> &operator=(const Container<LoadType> &sSrc);
		Container<LoadType> &operator=(Container<LoadType> &&sSrc);

	public:
		inline operator LoadType &();
		inline operator const LoadType &() const;
		
	public:
		inline bool loaded() const;
		inline LoadType &containedLoad();
		inline const LoadType &containedLoad() const;
		template<class ...ContructorParameter> inline void init(ContructorParameter &&...sConstructorParam);
		inline void fin();
	};

	template<class LoadType> inline Container<LoadType>::operator LoadType &()
	{
		return *reinterpret_cast<LoadType *>(this->vLoad);
	}

	template<class LoadType> inline Container<LoadType>::operator const LoadType &() const
	{
		return *reinterpret_cast<LoadType *>(this->vLoad);
	}

	template<class LoadType> inline bool Container<LoadType>::loaded() const
	{
		return this->bLoaded;
	}

	template<class LoadType> inline LoadType &Container<LoadType>::containedLoad()
	{
		return *reinterpret_cast<LoadType *>(this->vLoad);
	}

	template<class LoadType> inline const LoadType &Container<LoadType>::containedLoad() const
	{
		return *reinterpret_cast<LoadType *>(this->vLoad);
	}

	template<class LoadType> template<class ...ContructorParameter> inline void Container<LoadType>::init(ContructorParameter &&...sConstructorParam)
	{
		if (this->bLoaded)
			return;

		this->bLoaded = true;
		new (this->vLoad) LoadType(std::forward<LoadType>(sConstructorParam)...);
	}

	template<class LoadType> inline void Container<LoadType>::fin()
	{
		if (!this->bLoaded)
			return;

		this->bLoaded = false;
		(*reinterpret_cast<LoadType *>(this->vLoad)).~LoadType();
	}
}

#include "Container.hpp"

#endif