
namespace D3MCS
{
	template <class ManagerType> ManagerType *ManagerBase<ManagerType>::pInstance = nullptr;

	template <class ManagerType> template <class ...ContructorParameter> void ManagerBase<ManagerType>::initialize(ContructorParameter &&...sContructorParam)
	{
		if (!ManagerBase<ManagerType>::pInstance)
			ManagerBase<ManagerType>::pInstance = new ManagerType(std::forward<ContructorParameter>(sContructorParam)...);
	}

	template <class ManagerType> void ManagerBase<ManagerType>::finalize()
	{
		if (ManagerBase<ManagerType>::pInstance)
		{
			delete ManagerBase<ManagerType>::pInstance;
			ManagerBase<ManagerType>::pInstance = nullptr;
		}
	}
}