/*
 * [The "BSD 3-clause license"]
 * Copyright (c) 2012-2016 The ANTLR Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ANTLR_TREE_H__
#define __ANTLR_TREE_H__




ANTLR_BEGIN_DECLS


#define ANTLR_TYPE_TREE           (antlr_tree_get_type())
#define ANTLR_TREE(obj)           ((AntlrTree*)obj)
#define ANTLR_TREE_CLASS(klass)   ((AntlrTreeClass*)klass)
#define ANTLR_TREE_GET_CLASS(obj) ((AntlrTreeClass*)(antlr_type_get_class()[ANTLR_TYPE_TREE]))

typedef struct AntlrTree       AntlrTree;//!< AntlrTree type
typedef struct _AntlrTreeClass AntlrTreeClass;

/*
typedef void*                  AntlrTreeNode;
typedef GList*                 AntlrTreeNodeList;

typedef struct AntlrTree       AntlrContextTree;
typedef AntlrRuleContext       AntlrContextTreeNode;


TreeNode
 +- root
 +- parent
 +- children
TreeNodeList
 +- root
 +- parent
TreeRoot
 +- list
*/


/*!
 * \struct AntlrTree tree.h antlr/runtime.h
 * \extends AntlrObject
 * \brief The AntlrTree object
 *
 * Vacuum all input from a {@link Reader}/{@link InputStream} and then treat it
 * like a {@code char[]} buffer. Can also pass in a {@link String} or
 * {@code char[]} to use.
 *
 * If you need encoding, pass in stream/reader with correct encoding.
 *
 */
struct AntlrTree
{
   /*!
    * \brief The base class brief
    * \private
    *
    * The base class description
    */
    AntlrObject parent_instance;

    /*!
     * \brief The root of an AntlrTree*
     * 
     * The root of a AntlrTree*
     * If root is NULL then it is root of the tree
     */
    AntlrTree *root;/*SharedPtr*/
    /*!
     * \brief The parent of an AntlrTree*
     * 
     * The parent of a AntlrTreeNode
     */
    AntlrTree *parent;/*SharedPtr*/
    /*!
     * \brief A list of AntlrTree*
     * 
     * The children of a AntlrTreeNode
     */
    GList     *children;
};



/*!
 * \struct _AntlrTreeClass
 * \brief The vtable of AntlrTree
 * 
 * \internal
 */
struct _AntlrTreeClass
{
   /*!
    * \brief The base vtable
    * \protected
    *
    * The base vtable description
    */
    AntlrObjectClass parent_class;
};

/*!
 * \brief Get the AntlrType of AntlrTree object
 * 
 * Note than it is by this function than AntlrTree vtable has initialized
 * 
 * \relates AntlrTree
 */
AntlrType         antlr_tree_get_type(void);

/*!
 * \brief Create a new InputStream instance.
 * \return Output that is extra useful
 * \ingroup AntlrTree
 *
 * This method does unbelievably useful things.  
 * And returns exceptionally useful results.
 * Use it everyday with good health.
 *
 * \relates AntlrTree
 */
AntlrTree *antlr_tree_new(void);


ANTLR_END_DECLS


#endif // __ANTLR_TREE_H__
