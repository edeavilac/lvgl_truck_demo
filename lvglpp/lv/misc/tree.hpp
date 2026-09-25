#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/** @see lv_tree_node_class */
inline constexpr const lv_tree_class_t* tree_node_class = &lv_tree_node_class;

/**
 * Walk the tree recursively and call a callback function on each node
 * @param node  pointer to the root node of the tree
 * @param mode  LV_TREE_WALK_PRE_ORDER or LV_TREE_WALK_POST_ORDER
 * @param cb  callback function to call on each node
 * @param bcb  callback function to call before visiting a node
 * @param acb  callback function to call after visiting a node
 * @param user_data  user data to pass to the callback functions
 * @return true: traversal is finished; false: traversal broken
 * @see lv_tree_walk
 */
inline bool tree_walk(TreeNode node, TreeWalkMode mode, lv_tree_traverse_cb_t cb, lv_tree_before_cb_t bcb, lv_tree_after_cb_t acb, void* user_data) noexcept { return lv_tree_walk(node.raw(), static_cast<lv_tree_walk_mode_t>(mode), cb, bcb, acb, user_data); }

/**
 * Takes any callable instead of the C pair.
 * Walk the tree recursively and call a callback function on each node
 * @param node  pointer to the root node of the tree
 * @param mode  LV_TREE_WALK_PRE_ORDER or LV_TREE_WALK_POST_ORDER
 * @param cb  callback function to call on each node
 * @param bcb  callback function to call before visiting a node
 * @param acb  callback function to call after visiting a node
 * @param user_data  user data to pass to the callback functions
 * @return true: traversal is finished; false: traversal broken
 * @see lv_tree_walk
 */
template <class F>
inline bool tree_walk(TreeNode node, TreeWalkMode mode, lv_tree_before_cb_t bcb, lv_tree_after_cb_t acb, F&& f) noexcept { return lv_tree_walk(node.raw(), static_cast<lv_tree_walk_mode_t>(mode), detail::TreeTraverseCbClosure<std::decay_t<F>>::fn(f), bcb, acb, detail::TreeTraverseCbClosure<std::decay_t<F>>::state(f)); }

inline TreeNode TreeNode::create(const lv_tree_class_t* class_p, TreeNode parent) noexcept { return TreeNode(lv_tree_node_create(class_p, parent.raw())); }

inline void TreeNode::delete_() const noexcept { lv_tree_node_delete(p_); }

} // namespace lv
