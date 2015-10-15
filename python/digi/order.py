
class OrderVolumeNotMultipleOfTenError(ValueError):
    pass

class OrderVolumeNotMoreThanZeroError(ValueError):
    pass

class Order(object):

    def __init__(self, client_name, order_type, order_volume):
        if order_volume <= 0:
            raise OrderVolumeNotMultipleOfTenError
        if order_volume % 10 is not 0:
            raise OrderVolumeNotMoreThanZeroError
        self.__client_name = client_name
        self.__type = order_type
        self.__volume = order_volume

    @property
    def client_name(self):
        return self.__client_name

    @property
    def type(self):
        return self.__type

    @property
    def volume(self):
        return self.__volume

    def split_on_volume(self, volume):
        splited_volume = self.__volume - volume
        return [Order(self.__client_name, self.__type, volume),
                Order(self.__client_name, self.__type, splited_volume)]
