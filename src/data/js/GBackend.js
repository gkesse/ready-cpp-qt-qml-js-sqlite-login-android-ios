//===============================================
// properties
//===============================================
var m_obj = {}
//===============================================
function getObj() {
    m_obj.errors = []
    m_obj.dbSQL = null
    return m_obj
}
//===============================================
// errors
//===============================================
m_obj.clearErrors = () => {
    m_obj.errors = []
}

m_obj.addError = (_msg) => {
    m_obj.errors.push(_msg)
}

m_obj.getErrors = () => {
    return m_obj.errors.join("\n")
}


m_obj.hasErrors = () => {
    return (m_obj.errors.length !== 0)
}
//===============================================
// database
//===============================================
m_obj.isOpenDatabase = () => {
    if(!m_obj.dbSQL) {
        m_obj.addError("Erreur 2 lors de la connexion au données.")
        return false
    }
    return !m_obj.hasErrors()
}

m_obj.openDatabase = () => {
    m_obj.dbSQL = LocalStorage.openDatabaseSync("db_readydev.dat", "1.0", "Base de données de ReadyDev", 1000000);

    try {
        m_obj.dbSQL.transaction(function(tx) {
            tx.executeSql("create table if not exists _users ( " +
                          "_username text " +
                          ", _password text " +
                          ", _passwordHint text " +
                          ")")
        })
    }
    catch(e) {
        m_obj.addError(e)
    }

    return !m_obj.hasErrors()
}
//===============================================
// users
//===============================================
m_obj.onLogin = (_username, _password) => {
    m_obj.clearErrors()

    if(_username === "") {
        m_obj.addError("Le nom d'utilisateur est obligatoire.")
        return false
    }
    if(_password === "") {
        m_obj.addError("Le mot de passe est obligatoire.")
        return false
    }

    try {
        m_obj.dbSQL.transaction(function(tx) {
            var lResults = tx.executeSql("" +
                                        "select _password from _users " +
                                        "where _username = ? " +
                                        "", _username)

            if(lResults.rows.length === 0) {
                m_obj.addError("Vous n'avez pas de compte.")
                return false
            }
            if(lResults.rows.item(0)._password !== _password) {
                m_obj.addError("Le mot de passe est incorrect.")
                return false
            }
        })
    }
    catch(e) {
        m_obj.addError(e)
    }

    return !m_obj.hasErrors()
}

m_obj.onRegister = (_username, _password, _password2, _passwordHint) => {
    m_obj.clearErrors()

    if(_username === "") {
        m_obj.addError("Le nom d'utilisateur est obligatoire.")
        return false
    }
    if(_password === "") {
        m_obj.addError("Le mot de passe est obligatoire.")
        return false
    }
    if(_password2 === "") {
        m_obj.addError("La confirmation est obligatoire.")
        return false
    }
    if(_passwordHint === "") {
        m_obj.addError("Le question secrète est obligatoire.")
        return false
    }
    if(_password !== _password2) {
        m_obj.addError("Les mots de passe sont différents.")
        return false
    }

    try {
        m_obj.dbSQL.transaction(function(tx) {
            var lResults = tx.executeSql("" +
                                        "select _password from _users " +
                                        "where _username = ? " +
                                        "", _username)

            if(lResults.rows.length !== 0) {
                m_obj.addError("Vous avez déjà un compte.")
                return false
            }

            tx.executeSql("" +
                          "insert into _users " +
                          "values (?, ?, ?) " +
                          "", [_username, _password, _passwordHint]);
        })
    }
    catch(e) {
        m_obj.addError(e)
    }

    return !m_obj.hasErrors()
}

m_obj.onRetrieval = (_username, _passwordHint) => {
    m_obj.clearErrors()

    if(_username === "") {
        m_obj.addError("Le nom d'utilisateur est obligatoire.")
        return ""
    }
    if(_passwordHint === "") {
        m_obj.addError("Le question secrète est obligatoire.")
        return ""
    }

    var lPassword = ""

    try {
        m_obj.dbSQL.transaction(function(tx) {
            var lResults = tx.executeSql("" +
                                        "select _password, _passwordHint from _users " +
                                         "where _username = ? " +
                                        "", _username)

            if(lResults.rows.length === 0) {
                m_obj.addError("Vous n'avez pas de compte.")
                return ""
            }
            if(lResults.rows.item(0)._passwordHint !== _passwordHint) {
                m_obj.addError("La question secrètre est incorrecte.")
                return ""
            }

            lPassword = lResults.rows.item(0)._password
        })
    }
    catch(e) {
        m_obj.addError(e)
    }

    return lPassword
}
//===============================================
