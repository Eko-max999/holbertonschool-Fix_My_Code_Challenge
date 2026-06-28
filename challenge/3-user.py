#!/usr/bin/env python3
"""
User class
"""

class User():
    """ User class representing a system user """

    def __init__(self):
        """ Initialize internal password to None """
        self.__password = None

    @property
    def password(self):
        """ Getter for password """
        return self.__password

    @password.setter
    def password(self, password):
        """ Setter for password """
        if password is None or type(password) is not str:
            self.__password = None
        else:
            self.__password = password

    def is_valid_password(self, password):
        """ Check if the provided password matches the internal password """
        if password is None or type(password) is not str:
            return False
        if self.__password is None:
            return False
        return self.__password == password


if __name__ == "__main__":
    print("Test User")
    u = User()
    u.password = "Root1234"
    if not u.is_valid_password("Root1234"):
        print("is_valid_password should return True if it's the right password")
