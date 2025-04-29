#pragma once
#include "repo.h"
class UndoAction {
public:
        virtual void doUndo()=0;
        virtual ~UndoAction() = default;
};

class UndoAdd final : public UndoAction {
        Locatar addedLocatar;
        Repo& repo;
public:
        UndoAdd(Repo& repo,const Locatar& locatar): repo(repo), addedLocatar(locatar) {}
        void doUndo() override {
                repo.del(addedLocatar.getAp(), addedLocatar.getName());
        }
};

class UndoDel final : public UndoAction {
        Locatar deletedLocatar;
        Repo& repo;
public:
        UndoDel(Repo& repo,const Locatar& locatar): repo(repo), deletedLocatar(locatar) {}
        void doUndo() override {
                repo.add(deletedLocatar);
        }
};

class UndoModify final : public UndoAction {
        Locatar modifiedLocatar;
        int newAp;
        std::string newName;
        Repo& repo;
public:
        UndoModify(Repo& repo,const Locatar& locatar, const int ap, const std::string &name): modifiedLocatar(locatar), newAp(ap), newName(name), repo(repo) {}
        void doUndo() override {
                repo.modify(newAp, newName, modifiedLocatar);
        }
};